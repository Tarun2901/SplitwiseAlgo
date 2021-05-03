#include<iostream>
#include<set>
using namespace std;

int main()
{

int no_of_transactions,friends;
cin>>no_of_transactions>>friends;

int x,y,amount;
int cnt = 0;
// 1-D array to store the net amount that each person will to take at the end
int net[100000] = {0};
while(no_of_transactions--)
{
	cin>>x>>y>>amount;
    net[x]-=amount;
    net[y]+=amount;
}


 //We will take a muktiset because there might be multiple people having same net amount
 multiset<int> m;
 //Initialise a list and sort it
 for(int i = 0;i<friends;i++)
 {
 	if(net[i]!=0)
 	{
 		m.insert(net[i]);
 	}
 }
// Until the multiset is empty, we will pop out two people(left and right) and we will try to settle them 
while(!m.empty())
{
	auto low = m.begin();
	auto high = prev(m.end());
    
    int debit = *low;
    int credit = *high;

    //Remove these elements from the Multiset
    m.erase(low);
    m.erase(high);
    
    //Settlement
    int settlement_amount = min(-debit,credit);
    cnt++;
    //settlement_amount from debiter to crediter
    //one of debit or credit will be zero coz min is either debit or credit
    debit+=settlement_amount;
    credit-=settlement_amount;

    if(debit!=0)
    {
    	m.insert(debit);
    }
    if(credit!=0)
    {
    	m.insert(credit);
    }
}

cout<<cnt<<endl;

return 0;
}