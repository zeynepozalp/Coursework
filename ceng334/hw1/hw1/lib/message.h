#ifndef CENG334HOMEWORK1_MESSAGE_H
#define CENG334HOMEWORK1_MESSAGE_H

/*BIDDER MSG TYPES*/
#define CLIENT_CONNECT 1
#define CLIENT_BID 2
#define CLIENT_FINISHED 3

/*SERVER MSG TYPES*/
#define SERVER_CONNECTION_ESTABLISHED 1
#define SERVER_BID_RESULT 2
#define SERVER_AUCTION_FINISHED 3

/*SERVER MSG RESULTS*/
#define BID_ACCEPTED 0
#define BID_LOWER_THAN_STARTING_BID 1
#define BID_LOWER_THAN_CURRENT 2
#define BID_INCREMENT_LOWER_THAN_MINIMUM 3

typedef union client_message_parameters {
    int status;
    int bid;
    int delay;
} cmp;

typedef struct client_message {
    int message_id; //non-zero and unique message id
    cmp params;
} cm;

/*SERVER*/
typedef struct connection_established_info {
    int client_id;
    int starting_bid;
    int current_bid;
    int minimum_increment;
} cei;

/*SERVER*/
typedef struct bid_info {
    int result;
    int current_bid;
} bi;

/*SERVER*/
typedef struct winner_info {
    int winner_id;
    int winning_bid;
} wi;

/*SERVER*/
typedef union server_message_parameters {
    cei start_info;
    bi result_info;
    wi winner_info;
} smp;

/*MAIN SERVER*/
typedef struct server_message {
    int message_id; //non-zero and unique message id
    smp params;
} sm;

#endif //CENG334HOMEWORK1_MESSAGE_H
