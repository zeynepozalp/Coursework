#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/poll.h>
#include "logging.h"
#include "message.h"

#define PIPE(fd) socketpair(AF_UNIX, SOCK_STREAM, PF_UNIX, fd)

int main() {
	int startBid, minInc, noOfBidders;

	scanf("%d %d %d", &startBid, &minInc, &noOfBidders);

	int fds[noOfBidders][2];
	pid_t pids[noOfBidders];

	for(int i=0; i<noOfBidders; i++){
		int noOfArgs;
		char execPath[100];
		scanf("%s %d ", execPath, &noOfArgs);

		char *allArgs[noOfBidders+2][100];
        char args[noOfArgs][100];

		for(int j=0; j<noOfArgs; j++){
			scanf("%s", args[j]);
		}

        for(int j=1; j<noOfArgs+1; j++){
            allArgs[i][j]=args[j-1];
        }
		
        allArgs[i][0]=execPath;
        allArgs[i][noOfArgs+1]=NULL;

        PIPE(&fds[i][0]);
		pid_t pid=fork();

		if(pid) {
			close(fds[i][0]);
			pids[i]=pid;
		}
		else {
		    dup2(fds[i][0], 0);
		    dup2(fds[i][0], 1);
			close(fds[i][0]);
			close(fds[i][1]);

			execv(execPath, allArgs[i]);
			perror("");
		}

	}

	struct pollfd pfds[noOfBidders];
	for(int i=0; i<noOfBidders; i++){
		pfds[i].fd = fds[i][1];
		pfds[i].events = POLLIN;
	}

	int noOfActive = noOfBidders;
	int i=0;
	int winnerID;
    int clientStats[noOfBidders];
    int currBid = startBid;

	while(noOfActive){
		poll(pfds, noOfBidders, -1);
		for(int i=0; i<noOfBidders; i++){
			if (pfds[i].revents & POLLIN) {

				cm clientMsg;
				read(fds[i][1], &clientMsg, sizeof(clientMsg));

				switch (clientMsg.message_id) {
					case CLIENT_CONNECT:;
						ii inputData1 = {CLIENT_CONNECT, pids[i], clientMsg.params};
						print_input(&inputData1, i);

						cmp bidDelay = clientMsg.params;
						sm serverMsg1;
						serverMsg1.message_id = SERVER_CONNECTION_ESTABLISHED;
						smp start_info = {i, startBid, currBid, minInc};
						serverMsg1.params = start_info;
						write(fds[i][1], &serverMsg1, sizeof(sm));

						oi outputData1 = {SERVER_CONNECTION_ESTABLISHED, pids[i], serverMsg1.params};
						print_output(&outputData1, i);
						break;

					case CLIENT_BID:;
						int bid = clientMsg.params.bid;
						ii inputData2 = {CLIENT_BID, pids[i], clientMsg.params};
						print_input(&inputData2, i);

						sm serverMsg2;
						serverMsg2.message_id = SERVER_BID_RESULT;
						int result;

						if(bid<startBid) result = 1;
						else if(bid<currBid) result=2;
						else if((bid-currBid)<minInc) result=3;
						else{
                            currBid=bid;
							result=0;
							winnerID=i;
						}
						
						smp result_info={result, currBid};
						serverMsg2.params = result_info;
						write(fds[i][1], &serverMsg2, sizeof(sm));

						oi outputData2 = {SERVER_BID_RESULT, pids[i], serverMsg2.params};
						print_output(&outputData2, i);
						break;

					case CLIENT_FINISHED:;
                        clientStats[i] = clientMsg.params.status;

                        ii inputData3 = {CLIENT_FINISHED, pids[i], clientMsg.params};
						print_input(&inputData3, i);

						noOfActive--;
						break;
				}
		    }
	    }
    }

    print_server_finished(winnerID, currBid);

    sm serverMsg3;
	serverMsg3.message_id = SERVER_AUCTION_FINISHED;
    smp winner_info = {winnerID, currBid};
    serverMsg3.params = winner_info;

    for(int i=0; i<noOfBidders; i++){
        write(fds[i][1], &serverMsg3, sizeof(sm));
        oi outputData3 = {SERVER_AUCTION_FINISHED, pids[i], serverMsg3.params};
		print_output(&outputData3, i);
    }

    for(int i=0; i<noOfBidders; i++){
        int stat;
        waitpid(pids[i], &stat, 0);
        print_client_finished(i, clientStats[i], (clientStats[i]==WEXITSTATUS(stat)));
    }

    for(int i=0; i<noOfBidders; i++){
        close(fds[i][0]); close(fds[i][1]);
    }
	return 0;
}
