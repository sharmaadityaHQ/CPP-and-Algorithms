// https://www.interviewbit.com/problems/sorted-permutation-rank/

// O(n^2)

int mod = 1000003;

int fact(int n) {
    return (n<=1)?1:(n*fact(n-1)) %mod;
}

int Solution::findRank(string A) {
    int rank=1;
    for(int i=0;i<A.size();i++){
        int c=0;
        for(int j=i+1;j<A.size();j++) {
            if(A[i]>A[j])c++;
        }
        rank=(rank+(c*fact(A.size()-1-i))%mod)%mod;
    }
    return rank;
}

// O(n) by creating auxillary array, will not work with duplicate elements

int fact(int n) 
{ 
	return (n <= 1) ? 1 : n * fact(n - 1); 
} 

void populateAndIncreaseCount(int* count, char* str) 
{ 
	int i; 
	for (i = 0; str[i]; ++i){ 
		++count[str[i]]; 
    }
	for (i = 1; i < 256; ++i) 
		count[i] += count[i - 1]; 
} 
 
void updatecount(int* count, char ch) 
{ 
	int i; 
	for (i = ch; i < 256; ++i) 
		--count[i]; 
} 

int findRank(char* str) 
{ 
	int len = strlen(str); 
	int mul = fact(len); 
	int rank = 1, i; 

	int count[256] = { 0 }; 

	populateAndIncreaseCount(count, str); 

	for (i = 0; i < len; ++i) { 
		mul /= len - i; 
		rank += count[str[i] - 1] * mul; 
		updatecount(count, str[i]); 
	} 

	return rank; 
} 
