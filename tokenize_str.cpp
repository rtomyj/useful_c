/***************************************************************
 *	Method: tokenizeString() 
 * 
 *	Use:	Seperates a string into substrings where each subtring is seperated by a delimiter.
 * 
 *	Arguments:	1) String to split.
 * 				2) String to use as delimiter. Delimiter is used to seperate argument 1.
 * 
 *	Returns: Tokens - substrings obtained by splitting string by a delimiter
***************************************************************/
vector<string> tokenizeString(string subject, string delimiter)
{
	vector<string> tokens; // vector for valid tokens
	string token;		   // temp var for token

	size_t tokenStart = 0, tokenEnd;

	/*
	*	Searches string till it finds a delimiter. Token is extracted and tested for its usability. Empty string tokens are skipped
	*/
	while ((tokenEnd = subject.find(delimiter, tokenStart)) != string::npos)
	{
		token = subject.substr(tokenStart, tokenEnd - tokenStart);
		if (token != "")							// skip empty token
			tokens.push_back(token);				// add valid token to token vector
		tokenStart = tokenEnd + delimiter.length(); // position in string to start searching for new tokens
	}

	token = subject.substr(tokenStart, tokenEnd - tokenStart); // gets last portion of subject that might not be delimited to the right
	if (token != "")
		tokens.push_back(token);
	return tokens;
}
