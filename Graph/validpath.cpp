struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

bool notTouchingCircle(int x1,int y1,int r,vector<pair<int,int>> &center){


    for(int i=0;i<center.size(); i++){

        int c1=center[i].first;
        int c2=center[i].second;

        int d= (c1-x1)*(c1-x1) + (c2-y1)*(c2-y1);

        if(d<=(r*r))
          return false;



    }

    return true;

}

int d[8][2]={{1,1},{1,0},{0,1},{-1,-1},{-1,0},{0,-1},{-1,1},{1,-1}};

bool validCordinate(int x1,int y1,int x,int y){

    if(x1<0 || y1<0 || x1>x || y1>y)
    return false;


    return true;
}


bool checkValidPath(vector<pair<int,int>> &center, int x,int y, int n,int r){


    queue<pair<int,int>> q;

    //unordered_set<pair<int,int>,hash<pair<int,int>>> s; //unordered_set

    unordered_set< pair<int, int>, pair_hash > u_edge_;
    //unordered_map<pair<int,int>, int> m;
    //m[make_pair(0,0)]=1;

    int visited[x+1][y+1];
    memset(visited,0,sizeof(visited));

    q.push(make_pair(0,0));

   // s.insert(make_pair(0,0));


    while(!q.empty()){

        pair<int,int> curr=q.front();

        if(curr.first==x && curr.second==y)
               return true;

        q.pop();

        //now travers all the 8 valid vertices
        for(int i=0;i<8;i++){
            int x1=d[i][0] +curr.first;
            int y1=d[i][1] +curr.second;


            if(validCordinate(x1,y1,x,y)){
                //cout<<"hiii1"<<endl;
                if(visited[x1][y1]==0){
                    //cout<<"hiii2"<<endl;
                    if(notTouchingCircle(x1,y1,r,center)){
                        //cout<<"valid cordinate "<<x1<< " "<<y1;
                        //cout<<"hii3"<<endl;
                        //tahn insert int queue and map
                        q.push(make_pair(x1,y1));
                       // s.insert(make_pair(x,y));
                       //m[make_pair(x1,y1)]=1;
                       visited[x1][y1]=1;
                    }

                }

            }


        }

    }

    return false;

}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {

    int x=A,y=B,n=C,r=D;


    //lets store the centre of each circle in a pair

    vector<pair<int,int>>  centre;

    for(int i=0;i<E.size();i++){

        centre.push_back(make_pair(E[i],F[i]));

    }

   if(checkValidPath(centre,  x, y, n, r))
        return "YES";

    return "NO";
}
