//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int mod = 1e9+7;
const int mod2 = 998244353;

struct node{
    int data;
    node*next;
    node(){
        data=0;
        next=nullptr;
    }
};
class linkedlist{
public:
    node*head;
    linkedlist(){
        head=nullptr;
    }
    void push(int x){
        node*a=new node();
        a->data=x;
        a->next=head;
        head=a;
    }
};
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    linkedlist a;
    int n,k;
    cin>>n;
    while(n--){
        cin>>k;
        a.push(k);
    }
    int x=0;
    while(true){
        x++;
        node*b=a.head,*prevB=nullptr;
        bool c=1;
        while(b->next!=nullptr){
            if(b->next->data>=b->data){
                //del b
                if(b==a.head){
                    a.head=b->next;
                    b=b->next;
                }else{
                    prevB->next=b->next;
                    b=b->next;
                }
                c=0;
            }else{
                prevB=b;
                b=b->next;
            }
        }
        if(c)break;
    }
    cout<<x-1;
}
