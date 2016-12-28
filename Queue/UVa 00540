#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    for(int Case=1;;Case++){
        queue<int> Empty;
        queue<int> track;
        map<int,int> m;
        bool *done;
        scanf("%d",&N);
        if(N==0)
            break;
        done=new bool[N];
        memset(done,false,N);
        //vector< vector<int> > num(N);
        vector< queue<int> > v(N);
        for(int i=0;i<N;i++){
            int k;
            scanf("%d",&k);
            for(int j=0;j<k;j++){
                int temp;
                scanf("%d",&temp);
                //num[i].push_back(temp);
                m[temp]=i;
            }
        }
        string s;
        int val;
        cout<<"Scenario #"<<Case<<endl;
        while(cin>>s,s!="STOP"){
            if(s=="ENQUEUE"){
                cin>>val;
                if(done[m[val]]&&!v[m[val]].empty()){
                    v[m[val]].push(val);
                }else{
                    track.push(m[val]);
                    v[m[val]].push(val);
                    done[m[val]]=true;
                }
            }
            else{
                int index=track.front();
                cout<<v[index].front()<<endl;
                v[index].pop();
                if(v[index].empty()){
                    track.pop();

                }
            }
        }
        cout<<endl;
    }
    return 0;
}
