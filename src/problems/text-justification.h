//
//  text-justification.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed not to exceed L in length.
click to show corner cases.
Corner Cases:

A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.

*/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        int len = (int)words.size();
        
        int count = 0, wordLen = 0;
        vector<string> lineWords;
        for (int i=0; i<len; i++) {
            string j = words[i];
            if (count == 0) {
                wordLen = (int)j.length();
            }
            else {
                wordLen = ((int)j.length()+1);
            }
            
            if (count+wordLen > L) {
                result.push_back(lineJustify(lineWords, L, count, false));
                count = wordLen-1;
                lineWords.clear();
                lineWords.push_back(j);
            }
            else {
                count += wordLen;
                lineWords.push_back(j);
            }
        }
        
        result.push_back(lineJustify(lineWords, L, count, true));
        
        return result;
    }
    
    /**
     *  Return a justified line
     *
     *  @param lineWords input words
     *  @param L         line width
     *  @param count     words's length(including one space between two words
     *  @param lastLine  whether it's the last line
     *
     *  @return return the justified string
     */
    
    string lineJustify(vector<string> lineWords, int L, int count, bool lastLine) {
        int wordCount = (int)lineWords.size();
        
        int smallSpace;
        int bigSpace;
        int bigCount;
        
        if (lastLine || wordCount == 1) {
            bigSpace = 0;
            smallSpace = 0;
            bigCount = 0;
        }
        else {
            int totalSpace = L-count;
            
            smallSpace = totalSpace/(wordCount-1);
            bigSpace = smallSpace + 1;
            bigCount = totalSpace%(wordCount-1);
        }
        
        string result;
        for (int i=0; i<wordCount-1; i++) {
            result += lineWords[i];
            result += " ";
            if (bigCount > 0) {
                result += spaces(bigSpace);
                bigCount--;
            }
            else {
                result += spaces(smallSpace);
            }
        }
        result += lineWords[wordCount-1];
        
        int remain = L - (int)result.length();
        if (remain) {
            result += spaces(remain);
        }
        
        return result;
    }
    
    string spaces(int count) {
        string result;
        while (count > 0) {
            result += " ";
            count--;
        }
        return result;
    }
    
    void run() {
        vector<string> test;
        string testArray[5] = {"a","b","c","d","e"};
        test.assign(testArray, testArray+5);
        
        vector<string> result = fullJustify(test, 1);
        for (auto i=result.begin(); i!=result.end(); i++) {
            cout<<*i<<endl;
        }
    }
};