class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // BFS , bcz we need shortest sequence. So level order type traversal
        queue<pair<string,int>>q;
        //using set to check for every possible permmutation of word that we will be forming of the beginWord. 
        // Also we can erase if we find any possible permutation so as to not visit it again.
        unordered_set<string>st(wordList.begin(), wordList.end());
        
        q.push({beginWord,1});
        // Add it into queue and mark it visited by deleting it from the set
        st.erase(beginWord);

        while(q.size()>0){

            // The word we want to make permutations of
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word==endWord) return steps;

            for(int i=0; i<word.size(); i++){
                char original = word[i];
                // No we are going to make all possible permutations by replacing the char from a to z.
                for(char ch = 'a' ; ch <= 'z'; ch++){
                    
                    word[i]=ch;
                    // if any possible permutation is found then we add it to the queue and mark it visited
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                // restore the word to it's original state
                word[i]=original;
            }

        }


        return 0;
    }
};