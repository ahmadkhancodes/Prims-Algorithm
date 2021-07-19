#include <iostream>
using namespace std;
void display1();
int mat[7][7];
int too_visit[8];
int vvisited[8];
int connections[8];
int dist[10];

bool check_Login(string basicString, string basicString1);

void add_edge(int s, int e, int w) {
    mat[s][e] = w;
    mat[e][s] = w;
}

void initiate(){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            mat[i][j]=-1;
        }
    }
}

bool check_visited(int test) {
    for (int j = 0; j < 7; j++) {
        if (vvisited[j] == test) {
            return true;
        }
    }
    return false;
}



//int mat[7][7];
//
//void add_edge(int a,int b,int d){
//
//    mat[a][b]=d;
//    mat[b][a]=d;
//
//}
//void initiate(){
//    for(int i=0;i<7;i++){
//        for(int j=0;j<7;j++){
//            mat[i][j]=-1;
//        }
//    }
//}
//
//

void dijkistra(int st){
    int to_visit[100];
    int now = 0;
    bool visited[10];
    to_visit[0] = st;
    int visit_count = 1;
    for(int i=0;i<7;i++){
        visited[i]=false;
        dist[i]=999999;
    }
    dist[st]=0;
    for(int a=0;a<7;a++){
        for(int i=0;i<7;i++){
            if(mat[to_visit[now]][i]!=-1){
                if (visited[i] == false) {
                    to_visit[visit_count] = i;
                    visit_count++;
                    if (dist[i] > mat[to_visit[now]][i] + dist[to_visit[now]]) {
                        dist[i] = mat[to_visit[now]][i] + dist[to_visit[now]];
                    }
                    visited[to_visit[now]] = true;
                }

            }
        }
        now++;
//        for(int m=0;m<7;m++){
//            cout << dist[m]<<endl;
//        }
//        cout<<endl;



    }
}


void display(){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            cout<<mat[i][j]<<" ";

        }
        cout<<" "<<endl;
    }
    for(int i=0;i<7;i++){
        cout<<"Vertex "<<i<<"is connected to: ";
        for(int j=1;j<8;j++){
            if(mat[i][j]==1){
                cout<<j<<" ";
            }


        }
    }

}



void prims() {

    for (int i = 0; i < 7; i++) {
        connections[i] = -1;
        vvisited[i] = -1;
        too_visit[i] = -1;
    }

    int tv_last = 0;
    int tv_first = 0;
    int v_last = 0;
    int v_first = 0;
    int c = 0;

    int distance = 0;

    too_visit[tv_last] = 0;
    tv_last++;

    while (v_last!=6) {
        int now = too_visit[tv_first];
        for (int i = 0; i < 7; i++) {
            if (mat[now][i] != -1) {
                if (check_visited(i) == false) {
                    connections[c] = mat[now][i];
                    c++;
                }
            }
        }
        for (int i = 0; i < 7; i++) {
            cout << connections[i] << endl;
        }

        int smallest = 99999;
//        int smallest;
		for (int t = 0; t < 7; t++) {
            if (connections[t] != -1) {
                if (connections[t] < smallest) {
                    smallest = connections[t];
                }
            }
        }
        cout << smallest << endl;
        int small_vertex = -1;
        for (int t = 0; t < 7; t++) {
            if (mat[now][t] == smallest) {
                small_vertex = t;
            }
        }
        cout << small_vertex << endl;
        too_visit[tv_last] = small_vertex;
        vvisited[v_last] = now;
        v_last++;
        tv_last++;
        distance += smallest;
        tv_first++;
        for (int i = 0; i < 7; i++) {
            connections[i] = -1;
        }
        //c = 0;
		display1();
        //cout << "Distance is: "<< distance << endl;
    }

}

void display1() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cout << mat[i][j] << " ";
        }
        cout << " " << endl;
    }
}



int main()
{
//    for (int i = 0; i < 7; i++) {
//        for (int j = 0; j < 7; j++) {
//            mat[i][j] = -1;
//        }
//    }
    initiate();
    add_edge(0,1,28);
    add_edge(0,5,10);
    add_edge(1,2,16);
    add_edge(1,6,14);
    add_edge(2,3,12);
    add_edge(3,6,18);
    add_edge(3,4,22);
    add_edge(4,5,25);
    add_edge(4,6,24);

    string user="",pass="";
    cout << "Welcome to IP routing system" << endl;
    cout << "Enter Admin username" << endl;
    cin >> user;
    cout << "Enter Admin Pass" << endl;
    cin >> pass;

    if(check_Login(user,pass)){
        cout << "1) Shortest Distance" << endl;
        cout << "2) Map Cost" << endl;
        int choice=0;
        int selection=0;
        int selection2=0;
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Select starting IP" << endl;
                cout << "0) 192.168.1.2" << endl;
                cout << "1) 192.168.1.69" << endl;
                cout << "2) 192.168.1.732" << endl;
                cout << "3) 192.168.1.37" << endl;
                cout << "4) 192.168.10.9" << endl;
                cout << "5) 192.168.65.8" << endl;
                cout << "6) 192.168.45.976" << endl;
                cin >> selection;
                cout << "Select starting IP" << endl;
                cin >> selection2;
                dijkistra(selection);
                cout << "Shortest Distance to your Destination is: " << dist[selection2];
                break;
            case 2:
                prims();
                break;

        }
    }



}

bool check_Login(string basicString, string basicString1) {
    string admin_user="Admin",Admin_Pass="Admin";
    for(int i=0;i<5;i++){
        if(!admin_user[i]==basicString[i]){
            cout << "Invalid "<< endl;
            return false;
        }
    }
    return true;
}
