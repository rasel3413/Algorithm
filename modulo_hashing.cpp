#include <bits/stdc++.h>
// cerr << " Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << " ms  \n " ;
using namespace std;
#define int long long
#define pi acos(-1)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define debg cout << "yes" << endl;
#define fast ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define test int t;cin >> t; while (t--)
#define pb push_back
#define vec vector<int>
#define firs first
#define sec second
#define fo(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define ln length()
#define spc(x) cout << x << " ";
#define ent(x) cout << x << "\n";
#define mem(x, v) memset(x, v, sizeof(x));
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); debug(_it, args); }
void debug(istream_iterator<string> it) {}
template<typename T, typename... Args>
void debug(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl;   debug(++it, args...);}

int add(int a,int b,int mod)
{
    int res=(a+b)%mod;
    if(res<0)res+=mod;
    return res;
}
int mult(int a,int b,int mod)
{
    int res=(a*1LL*b)%mod;
    if(res<0)res+=mod;
    return res;

}
int power(int a,int b,int mod)
{
    int res=1;
    while(b){
        if(b%2==1)res=mult(res,a,mod);
        a=mult(a,a,mod);
        b/=2;
    }
    return res;
}
int mod_inverse(int a,int mod)
{
    return power(a,mod-2,mod);
}
int hashing(string s,int mod)
{
    int res=0;
    int pow=1;
    int p=31;
    for(char ch:s)
    {
        res=(res+((ch-'a'+1)*pow))%mod;
        pow=(pow*p)%mod;
    }
return res;
}
int Hash[1000000];
int inv[1000000];
void init_hashing(string s,int mod)
{
    int p=31;
    int pow=1;
    inv[0]=1;
 int pw_inv=power(p,mod-2,mod);

 for(int i=1;i<s.ln;i++)
 {
    inv[i]=mult(inv[i-1],pw_inv,mod);
 }
    Hash[0]=(s[0]-'a'+1);
    for(int i=1;i<s.ln;i++)
    {
        char ch=s[i];
        pow=(pow*p)%mod;
        Hash[i]=(Hash[i-1]+(ch-'a'+1)*pow)%mod;
    }
}
int substring(int l,int r,int mod)
{
    int res=Hash[r];

    if(l>0)res-=Hash[l-1];
    res=mult(res,inv[l],mod);
   
return res;

}

int32_t main()
{
   string s="srasel";
   init_hashing(s,1000000007);
   string ss="s";
   int res=hashing(ss,1000000007);
   int res1=substring(0,0,1000000007);
   deb(res,res1)


}
