#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/poll.h>
#include "lib/logging.c"
#include "lib/message.h"

#define PIPE(fd) socketpair(AF_UNIX, SOCK_STREAM, PF_UNIX, fd)

int main() {
    int startBid, minInc, noOfBidders, currBid;

    scanf("%d %d %d", &startBid, &minInc, &noOfBidders);
    currBid = startBid;

    int fds[noOfBidders][2];
    pid_t pids[noOfBidders];

    for (int i = 0; i < noOfBidders; i++) {
        int noOfArgs;
        char execPath[100];
        scanf("%s %d ", execPath, &noOfArgs);

        char *execArgs[noOfArgs + 2];
        execArgs[0] = execPath;
        execArgs[noOfArgs + 1] = NULL;

        char args[noOfArgs][100];
        for (int j = 0; j < noOfArgs; j++) {
            scanf("%s", args[j]);
            execArgs[j + 1] = args[j];
        }
        PIPE(&fds[i][0]);

        pid_t pid = fork();
        if (pid) {
            close(fds[i][0]);
            pids[i] = pid;
        } else {
            dup2(fds[i][0], 0);
            dup2(fds[i][0], 1);

            for (int j = 0; j <= i; j++) {
                close(fds[j][0]);
                close(fds[j][1]);
            }

            execv(execPath, execArgs);
        }

    }

    struct pollfd pfds[noOfBidders];
    for (int i = 0; i < noOfBidders; i++) {
        pfds[i].fd = fds[i][1];
        pfds[i].events = POLLIN;
    }

    int noOfActive = noOfBidders;
    int i = 0;
    int winnerID;

    while (noOfActive) {
        poll(pfds, noOfBidders, -1);
        for (int i = 0; i < noOfBidders; i++) {
            if (pfds[i].revents & POLLIN) {
                // fds[i][1] is readable

                cm clientMsg;
                read(fds[i][1], &clientMsg, sizeof(clientMsg));

                switch (clientMsg.message_id) {
                    case CLIENT_CONNECT:;
                        ii inputData1 = { CLIENT_CONNECT, pids[i], clientMsg.params };
                        print_input(&inputData1, i);

                        cmp bidDelay = clientMsg.params;
                        sm serverMsg1;
                        serverMsg1.message_id = SERVER_CONNECTION_ESTABLISHED;
                        smp start_info = { i, startBid, currBid, minInc };
                        serverMsg1.params = start_info;
                        write(fds[i][1], &serverMsg1, sizeof(sm));

                        oi outputData1 = { SERVER_CONNECTION_ESTABLISHED, pids[i], serverMsg1.params };
                        print_output(&outputData1, i);
                        break;

                    case CLIENT_BID:;
                        int bid = clientMsg.params.bid;
                        ii inputData2 = { CLIENT_BID, pids[i], clientMsg.params };
                        print_input(&inputData2, i);

                        sm serverMsg2;
                        serverMsg2.message_id = SERVER_BID_RESULT;
                        int result;

                        if (bid < startBid) result = 1;
                        else if (bid < currBid) result = 2;
                        else if (bid - currBid < minInc) result = 3;
                        else {
                            result = 0;
                            currBid = bid;
                            winnerID = i;
                        }

                        smp result_info = { result, currBid };
                        serverMsg2.params = start_info;
                        write(fds[i][1], &serverMsg2, sizeof(sm));

                        oi outputData2 = { SERVER_BID_RESULT, pids[i], serverMsg2.params };
                        print_output(&outputData2, i);
                        break;

                    case CLIENT_FINISHED:;
                        int clientStat = clientMsg.params.status;
                        printf("%d\n", clientStat);
                        noOfActive--;
                }
            }
        }
    }

    return 0;
}
