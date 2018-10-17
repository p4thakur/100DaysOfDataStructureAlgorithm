vector<int> parent,ranK; //rank,set is  keyword don't use them

//vector<pair<int ,pair<int,int>>> edges ;  or i can make it local both will work
//remeber to clear it if i am declaring it outside the scope of function:)




void initializeParentRank(int n){
    parent.clear();
    ranK.clear();
    //and i can add below thing if i don't wanna use pushback
    //parent.resize(n+1);
    //ranK.resize(n+1);
    for(int i=0;i<=n;i++){
        
        parent.push_back(i);
        ranK.push_back(0);
        //or
        //parent[i]=i;
        //ranK[i]=0;
        
    }
}


int Set(int u){
    
    if(parent[u]!=u)
        return  Set(parent[u]);
      
    return u ;
       
}


void merge(int u,int v){
    
    int v1=Set(u);
    int v2=Set(v);
    
    if(ranK[v1]>ranK[v2]){
        
        parent[v2]=v1;
    }
    
    else if(ranK[v1]<ranK[v2]){
        
        parent[v1]=v2;
    }
    
    else{
        parent[v1]=v2;
        ranK[v2]=ranK[v1]+1;
    }
    
}

bool checkCycle(int u, int v){
    
    //cout<<"hello1";
    if(Set(u)!=Set(v))
    {
        ///cout<<"hello";
     merge(u,v);
     return false;   
    }
    
   return true; 
}


 
int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<pair<int ,pair<int,int>>> edges ;
    int row=B.size();
    int col=B[0].size();
    
       edges.clear();
    //eges.resize(); //may be its requires
    
    for(int i=0;i<row;i++){
    
        int x=B[i][0];
        int y=B[i][1];
        int cost=B[i][2];
        
        pair<int, pair<int,int>> edge=make_pair(cost,make_pair(x,y));
      
        edges.push_back(edge);
       // cout<<"HIIII3"<<endl;
    }
    
    //cout<<"hiiii"<<endl;
    
    
    //applying kruskal algorithem
    //cout<<"hiiii4"<<endl;
    sort(edges.begin(), edges.end());
    
    
    int count=0;
    
    initializeParentRank(A);
    int totalCost=0;
   for(int i=0;i<row;i++)
   {
       
       //if(count==A-1)break; This part not neede ,But its good for optimization
       
       int u=edges[i].second.first;
       int v=edges[i].second.second;
       int cost=edges[i].first;
       
       if(!checkCycle(u,v))
       { //cout<<"hii1";
           //count++;
           totalCost+=cost;
           
       }
   }
   
   return totalCost;
    
    
}
