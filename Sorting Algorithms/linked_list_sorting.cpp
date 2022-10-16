class Solution {
public:
    void merge(vector<int> &v,int l,int q,int u)
    {
        vector<int>tmp;
        int lw=l,up=q+1;
       while(lw<=q && up<=u)
        {
            if(v[lw]<v[up])
            {tmp.push_back(v[lw]);
             lw++;
            }
           else
           {
             tmp.push_back(v[up])  ;
               up++;
           }
              
        }
        while(lw<=q)
        {
            tmp.push_back(v[lw]);
            lw++;
        }
        while(up<=u)
        {
            tmp.push_back(v[up]);
            up++;
        }
        for(int i=l;i<=u;i++)
        {
            v[i]=tmp[i-l];
        }
    }
    void mergesort(vector<int> &v,int l,int u)
    {
        if(l==u)
            return ;
        int q=(l+u)/2;
        mergesort(v,l,q);
        
        mergesort(v,q+1,u);
        merge(v,l,q,u);
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode*ptr=head;
        vector<int>arr;
        
        while(ptr!=NULL)
        {
            arr.push_back(ptr->val);
            ptr=ptr->next;
            
        }
     mergesort(arr,0,arr.size()-1);
        ptr=head;
        for(int x:arr)
        {
            ptr->val=x;
            ptr=ptr->next;
        }
        return head;
    }
};
