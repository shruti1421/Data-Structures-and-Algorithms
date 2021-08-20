    int finddup(set<vector<int>> s, vector<int>pre, vector<int> in, int n)
    {
        if(n<=1)
        return 0;
        
        int ele=pre[0];
         
        vector<int> leftin(n,0),rightin(n,0);
        int leftsize=0,rightsize=0; 
         
        int i=0; 
        while(ele!=in[i]&&i<n)
        {
            leftin[i]=in[i];
            i++;
        }
        
        leftsize=i;
        int j=0;
        i++;
        if(i<n&&ele==in[i])
        {
            leftsize=i;
            i++;
        }
        while(i<n)
        {
            rightin[j++]=in[i];
            i++;
        }
        
        rightsize=j;
        
        vector<int> leftpre(leftsize,0),rightpre(rightsize,0);
         
         j=1;
        for(i=0;i<leftsize;i++)
        leftpre[i]=pre[j++];
        
        for(i=0;i<rightsize;i++)
        rightpre[i]=pre[j++];
        
        if(s.find(leftpre)!=s.end()||s.find(rightpre)!=s.end())
        return 1;
        else
        {
            if(leftsize>1)
            s.insert(leftpre);
            if(rightsize>1)
            s.insert(rightpre);
        }
        
        return finddup(s,leftpre,leftin,leftsize)||finddup(s,rightpre,rightin,rightsize);
        
    }