#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class movieTicket{
private:
unordered_map<int,unordered_set<int>>mb;
unordered_map<int,int>tickets;
public:
bool book(int X,int Y){
    if(mb[Y].count(X)||tickets[Y]>=100)
    return false; 
     mb[Y].insert(X);
    tickets[Y]++;
    return true;
}
bool Cancel(int X, int Y){
if(!mb[Y].count(X))
return false;
mb[Y].erase(X);
tickets[Y]--;
return true;

}
bool IS_BOOKED(int X,int Y){
if(mb[Y].count(X))
return true;
else 
return false;
}
int AVAILABLE_TICKETS(int Y){
    return 100-tickets[Y];
}
};

int main(){
    movieTicket mt;
    int Q;
    cin>>Q;
while(Q--){
string query;
cin>>query;
if (query=="book"){
    int X,Y;
    cin>> X,Y;
    cout<<mt.book(X,Y)<<endl;
}
else if (query=="cancel"){
    int X,Y;
    cin>> X,Y;
    cout<<mt.Cancel(X,Y)<<endl;
}
else if (query=="IS_BOOKED"){
    int X,Y;
    cin>> X,Y;
    cout<<mt.IS_BOOKED(X,Y)<<endl;
}else  if(query=="AVAILABLE_TICKETS"){
    int Y;
    cin>>Y ;
    cout<<mt.AVAILABLE_TICKETS(Y)<<endl;
}
}
return 0;

    }
