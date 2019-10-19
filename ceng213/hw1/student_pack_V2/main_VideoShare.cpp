#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "VideoShare.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    VideoShare vs1 = VideoShare();
    vs1.loadUsers("listUser10.txt");
    vs1.loadVideos("listVideo10.txt");

    cout << " All Users" << endl;
    vs1.printAllUsers();
    cout << " All Videos" << endl;
    vs1.printAllVideos();

    //add friendship
    cout<<"Add Friendship"<<endl;
    vs1.addFriendship("userName284", "userName341");
    vs1.addFriendship("userName284", "userName392");
    vs1.addFriendship("userName284", "userName265");
    vs1.addFriendship("userName284", "userName163");

    cout << "Friends  of userName284" << endl;
    vs1.printFriendsOfUser("userName284");

    cout << "Friends  of userName341" << endl;
    vs1.printFriendsOfUser("userName341");

    //remove friendship
    cout<<"Remove Friendship"<<endl;
    vs1.removeFriendship("userName284", "userName341");
    cout << "Friends  of userName284" << endl;
    vs1.printFriendsOfUser("userName284");

    cout << "Friends  of userName341" << endl;
    vs1.printFriendsOfUser("userName341");

    cout<<"Add Subscription"<<endl;
    vs1.subscribe("userName056", "title384");
    vs1.subscribe("userName056", "title061");
    vs1.subscribe("userName056", "title135");


    vs1.subscribe("userName341", "title061");
    vs1.subscribe("userName341", "title051");
    vs1.subscribe("userName341", "title384");

    cout << "Subscriptions of userName056" << endl;
    vs1.printUserSubscriptions("userName056");

    cout << "Subscriptions of userName341" << endl;
    vs1.printUserSubscriptions("userName341");
    
    cout<<"sortUserSubscriptions"<<endl;
    vs1.sortUserSubscriptions("userName056");

     cout << "Subscriptions of userName056" << endl;
    vs1.printUserSubscriptions("userName056");

    cout << "Subscriptions of userName341" << endl;
    vs1.printUserSubscriptions("userName341");
    //printing Common Subscriptions    
    cout<<"printCommonSubscriptions"<<endl;
    vs1.sortUserSubscriptions("userName056");
    vs1.sortUserSubscriptions("userName341");
    vs1.printCommonSubscriptions("userName341","userName056");
    
    cout<<"ADDITIONAL TESTS.."<<endl;
    vs1.subscribe("userName392", "title353");
    vs1.subscribe("userName392", "title384");
    vs1.subscribe("userName392", "title343");
    
    vs1.subscribe("userName265", "title311");
    vs1.subscribe("userName265", "title061");
    vs1.subscribe("userName265", "title384");
    
    vs1.subscribe("userName163", "title353");
    vs1.subscribe("userName163", "title109");
    vs1.subscribe("userName163", "title061");
    vs1.subscribe("userName163", "title384");
    //printing Friend Subscriptions    
    cout << "Subscriptions of userName284's friends" << endl;    
    vs1.printFriendSubscriptions("userName284");
    cout << "Subscriptions of userName341's friends" << endl;        
    vs1.printFriendSubscriptions("userName341");
    cout<<"END OF TESTS.."<<endl;
    
    return 0;
}
