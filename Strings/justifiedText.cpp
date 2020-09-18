// https://www.interviewbit.com/problems/justified-text/

string JoinALineWithSpace( 
    vector<string>& words, 
    int start, int end, 
    int num_spaces) 
{ 
  
    // Number of words in current line 
    int num_words_curr_line 
        = end - start + 1; 
  
    // String to store the justified text 
    string line; 
  
    for (int i = start; i < end; i++) { 
  
        line += words[i]; 
        --num_words_curr_line; 
  
        // Count number of current space needed 
        int num_curr_space 
            = ceil((double)(num_spaces) 
                   / num_words_curr_line); 
  
        // Insert spaces in string line 
        line.append(num_curr_space, ' '); 
  
        // Delete the spaces inserted in line 
        num_spaces -= num_curr_space; 
    } 
  
    // Insert word to string line 
    line += words[end]; 
    line.append(num_spaces, ' '); 
  
    // Return justified text 
    return line; 
} 
  
// Function that justify the words of 
// sentence of length of line L 
vector<string> JustifyText( 
    vector<string>& words, 
    int L) 
{ 
  
    int curr_line_start = 0; 
    int num_words_curr_line = 0; 
    int curr_line_length = 0; 
  
    // To store the justified text 
    vector<string> result; 
  
    // Traversing the words array 
    for (int i = 0; i < words.size(); i++) { 
  
        // curr_line_start is the first word 
        // in the current line, and i is 
        // used to identify the last word 
        ++num_words_curr_line; 
  
        int lookahead_line_length 
            = curr_line_length 
              + words[i].size() 
              + (num_words_curr_line - 1); 
  
        // If by including the words length becomes L, 
        // then that set of words is justified 
        // and add the justified text to result 
        if (lookahead_line_length == L) { 
  
            // Justify the set of words 
            string ans 
                = JoinALineWithSpace( 
                    words, 
                    curr_line_start, 
                    i, 
                    i - curr_line_start); 
  
            // Store the justified text in result 
            result.emplace_back(ans); 
  
            // Start the current line 
            // with next index 
            curr_line_start = i + 1; 
  
            // num of words in the current line 
            // and current line length set to 0 
            num_words_curr_line = 0; 
            curr_line_length = 0; 
        } 
  
        // If by including the words such that 
        // length of words becomes greater than L, 
        // then hat set is justified with 
        // one less word and add the 
        // justified text to result 
        else if (lookahead_line_length > L) { 
  
            // Justify the set of words 
            string ans 
                = JoinALineWithSpace( 
                    words, 
                    curr_line_start, 
                    i - 1, 
                    L - curr_line_length); 
  
            // Store the justified text in result 
            result.emplace_back(ans); 
  
            // Current line set to current word 
            curr_line_start = i; 
  
            // Number of words set to 1 
            num_words_curr_line = 1; 
  
            // Current line length set 
            // to current word length 
            curr_line_length = words[i].size(); 
        } 
  
        // If length is less than L then, 
        // add the word to current line length 
        else { 
            curr_line_length 
                += words[i].size(); 
        } 
    } 
  
    // Last line is to be left-aligned 
    if (num_words_curr_line > 0) { 
        string line 
            = JoinALineWithSpace( 
                words, 
                curr_line_start, 
                words.size() - 1, 
                num_words_curr_line - 1); 
  
        line.append( 
            L - curr_line_length 
                - (num_words_curr_line - 1), 
            ' '); 
  
        // Insert the last line 
        // left-aligned to result 
        result.emplace_back(line); 
    } 
  
    // Return result 
    return result; 
} 
vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> result = JustifyText(A, B); 
    return result;
}
