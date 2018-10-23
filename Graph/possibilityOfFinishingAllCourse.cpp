#define WHITE 0
#define BLUE 1
#define GREY 2

void dfs(int index, vector<int> &visited, vector<vector<int>> &edges,int &mark){
   // cout<<"HII2"<<endl;
    visited[index]=BLUE;

    vector<int>::iterator it;
    //cout<<"index vale "<<index<<endl;

    for(it=edges[index].begin(); it!=edges[index].end() ;it++){

        //check if already present in stack
        //cout<<"visieted value"<< *it <<"c0lor "<<visited[*it]<<endl;
        if(visited[*it]==BLUE)
            { mark=1;
            return;
            //cout<<"hii"<<endl;

            }
            else if(visited[*it]==WHITE) /// this is important so i won't fall in loop
            dfs(*it, visited,edges,mark);


    }

    visited[index]=GREY; //remeber why you need to do this


}
int Solution::solve(int A, vector<int> &B, vector<int> &C) {

    int size=B.size();
   // vector<vector<int>> edges(A);//(size, vector<int>(size,0));

   vector<vector<int> > edges(A+1, vector<int>());

  // vector<vector<int>> edges;

   // edges.clear();

    for(int i=0;i<B.size();i++){

        edges[B[i]].push_back(C[i]);

    }
    //cout<<"hiii"<<endl;
    vector<int> visited(A+1,WHITE);
    int mark=0;
    for(int i=1;i<=A;i++)
    {

        if(visited[i]==WHITE  && mark==0){
            dfs(i, visited, edges,mark);
        }
    }

    //if mark 1 than it is not possible to get cover all coursea
    return !mark;

}
