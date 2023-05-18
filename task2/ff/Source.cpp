#include "pch.h"
#include<iostream>
#include<String>
#include<map>
using namespace std;

struct arrow
{
	char val;
	int next;
};

struct node
{
	arrow arrows[38];
};

class DFA
{
private:
	int current_state;
	node states[41];
	map <int, string> finalStateVal =
	{ { 15,"reserved word 'if'" },{ 29,"reserved word 'then'" },{ 30,"reserved word 'else'" },{ 24,"reserved word 'end'" },{ 38,"reserved word 'repeat'" },
		{ 33,"reserved word 'read'" },{ 36,"reserved word 'until'" },{ 37,"reserved word 'write'" },{8,"airthimetic operator"},
		{9,"comparison operator"},{10,"parentheses"},{11,"curly brackets"},{12,"symbol semicolon"},
		{21,"equal operator"},{14,"number"},{39,"double quotes"},{40,"comma"}, };
	map <char, int> arrowVal = { {'i',1}, {'f',2}, {'t',3}, { 'h',4}, { 'e',5}, { 'n',6}, { 'l',7}, { 's',8}, { 'd',9}, { 'r',10}, { 'p',11}, { 'a',12}, { 'u',13 }, {'w',14}, { '+',15}, { '-', 16}, {'*',17}, { '/',18 }, {'=',19 }, {'<',20}, { '(',21}, { ')',22}, { '{',23 }, {'}',24}, { ';',25}, { ':',26}, { '0',27}, { '1',28}, { '2',29}, { '3',30}, { '4', 31}, {'5',32}, { '6',33}, { '7',34}, { '8',35}, { '9',36},{'"',37},{',',38 } };
	string word = "";
	char vals[38] = { 'i', 'f', 't', 'h', 'e','n','l','s','d','r','p','a','u','w','+','-','*','/','=','<','(', ')', '{', '}',';',':','0','1','2','3','4','5','6','7','8','9','"',',' };
	
	const int transation_table[41][38] =
	{
		{4	,	NULL,	5	,	NULL,	1	,	NULL,	NULL,	NULL,	NULL,	2	,	NULL,	NULL,	6	,	7	,	8	,	8	,	8	,	8	,	9	,	9	,	10	,	10	,	11	,	11	,	12	,	13	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14  ,39	 ,	40},
		{NULL,	NULL,	NULL,	NULL,	NULL,	18	,	17	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	3	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	25	,	27	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	15	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	16	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	19  ,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	20	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	21	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	22	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	23	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	24	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	26	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{28	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	29	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	30	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	31	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{32	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	33	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	34	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	35	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	36	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	37	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	38	,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
		{NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,NULL,NULL},
	};

public:
	string final_tokens_steam;
	string final_lexeme_steam;
	string new_tokens[100];
	string new_tokens_type[100];
	int num_tokens;
	string id = "";
	string error = "";
	string errors = "";
	int code_lines = 0;
	// syntax
	string new_tokens_syntax_type[100];
	// syntax
	string new_tokens_syntax_type1[100];

	DFA() {
		/// Initialization arrows  with char-value for each node 'state'
		for (int i = 0; i < 41; i++)
			for (int j = 0; j < 38; j++)
				states[i].arrows[j].val = vals[j];
		/// Initialization arrows  with next value 'state'
		for (int ii = 0; ii < 41; ii++)
			for (int jj = 0; jj < 38; jj++)
				states[ii].arrows[jj].next = transation_table[ii][jj];
	}

	void processString(string str)
	{
		string tokens[100];
		string tokens_type[100];
		num_tokens = 0;
		current_state = 0;
		/// convert string to tokens
		for (int i = 0; i < str.length(); i++) {
			if (arrowVal[str[i]] != 0)
			{
				if (states[current_state].arrows[arrowVal[str[i]] - 1].next != NULL)
				{
					word += str[i];
					current_state = states[current_state].arrows[arrowVal[str[i]] - 1].next;
				}
				else
				{
					if (!word.empty())
					{
						tokens[num_tokens] = word;
						tokens_type[num_tokens] = finalStateVal[current_state];
						if (finalStateVal[current_state].empty()) {
							num_tokens--;
							for (int i = 0; i < word.length(); i++) {
								if (isalpha(word[i])) {
									id += word[i];
									if (error != "") {
										tokens[++num_tokens] = error;
										tokens_type[num_tokens]="ERROR";
										error = "";
									}
									if (i == word.length() - 1 && id != "") {
										tokens[++num_tokens ] = id;
										tokens_type[num_tokens] = "ID";
										id = "";
									}
								}
								else {
									if (id != "") {
										tokens[++num_tokens] = id;
										tokens_type[num_tokens] = "ID";
										id = "";
									}
									error += word[i];
									if (i == word.length() - 1 && error != "") {
										tokens[num_tokens] = error;
										tokens_type[num_tokens] = "ERROR";
										error = "";
									}
								}
							}
						}
							
						num_tokens++;
						current_state = 0;
						word = "";
						i--;
					}
					else
					{
						
						word += str[i];
						tokens[num_tokens] = word;
						tokens_type[num_tokens] = finalStateVal[current_state];
						if (finalStateVal[current_state].empty()) {
							num_tokens--;
							for (int i = 0; i < word.length(); i++) {
								if (isalpha(word[i])) {
									id += word[i];
									if (error != "") {
										tokens[++num_tokens] = error;
										tokens_type[num_tokens] = "ERROR";
										error = "";
									}
									if (i == word.length() - 1 && id != "") {
										tokens[++num_tokens] = id;
										tokens_type[num_tokens] = "ID";
										id = "";
									}
								}
								else {
									if (id != "") {
										tokens[++num_tokens] = id;
										tokens_type[num_tokens] = "ID";
										id = "";
									}
									error += word[i];
									if (i == word.length() - 1 && error != "") {
										tokens[num_tokens] = error;
										tokens_type[num_tokens] = "ERROR";
										error = "";
									}
								}
							}
						}
						num_tokens++;
						current_state = 0;
						word = "";
					}
				}
			}
			else
			{
				if (!word.empty())
				{
					tokens[num_tokens] = word;
					tokens_type[num_tokens] = finalStateVal[current_state];
					if (finalStateVal[current_state].empty()) {
						num_tokens--;
						for (int i = 0; i < word.length(); i++) {
							if (isalpha(word[i])) {
								id += word[i];
								if (error != "") {
									tokens[++num_tokens] = error;
									tokens_type[num_tokens] = "ERROR";
									error = "";
								}
								if (i == word.length() - 1 && id != "") {
									tokens[++num_tokens] = id;
									tokens_type[num_tokens] = "ID";
									id = "";
								}
							}
							else {
								if (id != "") {
									tokens[++num_tokens] = id;
									tokens_type[num_tokens] = "ID";
									id = "";
								}
								error += word[i];
								if (i == word.length() - 1 && error != "") {
									tokens[num_tokens] = error;
									tokens_type[num_tokens] = "ERROR";
									error = "";
								}
							}
						}
					}
					num_tokens++;
					current_state = 0;
					word = "";
				}
				word += str[i];
				if (isalpha(str[i])) {
					tokens[num_tokens] = word;
					tokens_type[num_tokens] = "ID";
				}
				else {
					tokens[num_tokens] = word;
					tokens_type[num_tokens] = "ERROR";
				}
				num_tokens++;
				word = "";
			}
		}
		if (!word.empty())
		{
			tokens[num_tokens] = word;
			tokens_type[num_tokens] = finalStateVal[current_state];
			if (finalStateVal[current_state].empty()) {
				num_tokens--;
				for (int i = 0; i < word.length(); i++) {
					if (isalpha(word[i])) {
						id += word[i];
						if (error != "") {
							tokens[++num_tokens] = error;
							tokens_type[num_tokens] = "ERROR";
							error = "";
						}
						if (i == word.length() - 1 && id != "") {
							tokens[++num_tokens] = id;
							tokens_type[num_tokens] = "ID";
							id = "";
						}
					}
					else {
						if (id != "") {
							tokens[++num_tokens] = id;
							tokens_type[num_tokens] = "ID";
							id = "";
						}
						error += word[i];
						if (i == word.length() - 1 && error != "") {
							tokens[num_tokens] = error;
							tokens_type[num_tokens] = "ERROR";
							error = "";
						}
					}
				}
			}
			num_tokens++;
		}

		/// preprocess tokens
		int j = 0, i = 0;
		new_tokens[j] = tokens[i];
		new_tokens_type[j] = tokens_type[i];
		for (i = 1; i < num_tokens; i++)
		{
			if (new_tokens_type[j] == "ID" && (tokens_type[i] == "ID" || tokens_type[i] == "number" || tokens_type[i].empty()))
			{
				new_tokens[j] += tokens[i];
				new_tokens_type[j] = "ID";
			}
			else if (new_tokens_type[j] == "ERROR" && (tokens_type[i] == "ERROR" || tokens_type[i].empty())) {
				new_tokens[j] += tokens[i];
				new_tokens_type[j] = "ERROR";
			}
			else if (tokens_type[i] == "double quotes")
			{
				j++;
				new_tokens[j] = tokens[i];
				new_tokens_type[j] = "String";
				i++;
				while (tokens_type[i] != "double quotes")
				{
					new_tokens[j] += tokens[i];
					new_tokens_type[j] = "String";
					i++;
				}
				new_tokens[j] += tokens[i];
				new_tokens_type[j] = "String";
				j++;
			}
			else if (tokens_type[i] == "curly brackets")
			{
				j++;
				new_tokens[j] = tokens[i];
				new_tokens_type[j] = "comment";
				i++;
				while (tokens_type[i] != "curly brackets")
				{
					new_tokens[j] += tokens[i];
					new_tokens_type[j] = "comment";
					i++;
				}
				new_tokens[j] += tokens[i];
				new_tokens_type[j] = "comment";
				j++;
			}
			else
			{
				j++;
				new_tokens[j] = tokens[i];
				new_tokens_type[j] = tokens_type[i];
			}
		}

		num_tokens = j + 1;

		/// preprocessing for GUI
		final_tokens_steam = "";
		final_lexeme_steam = "";
		for (int i = 0; i < num_tokens; i++)
		{
			if (!new_tokens[i].empty() && !new_tokens_type[i].empty())
			{
				final_lexeme_steam += new_tokens[i] + "\n";
				final_tokens_steam += new_tokens_type[i] + "\n";
			}
		}
		
		/// ------------------------------- preprocessing before syntax processing -------------------------------
		
		int num = 0;
		string* syntax_tokens1 = new string[num_tokens];

		for (int i = 0; i < num_tokens; i++)
			if (new_tokens_type[i] != "parentheses" && new_tokens_type[i] != "curly brackets" && new_tokens_type[i] != "comment" && !new_tokens_type[i].empty())
			{
				syntax_tokens1[num] = new_tokens_type[i];
				num++;
			}


		/// --------------------------- preprocess tokens for expressions replacement ---------------------------
		int jj = 0, ii = 0, num2=0;
		string* syntax_tokens2 = new string[num];
		syntax_tokens2[jj] = syntax_tokens1[ii];
		ii++;
		num2++;
		for (; ii < num; ii++)
		{
			if (syntax_tokens1[ii] == "airthimetic operator")
			{
				if ((syntax_tokens1[ii + 1] == "number" || syntax_tokens1[ii + 1] == "ID" || syntax_tokens1[ii + 1] == "String") && (syntax_tokens1[ii - 1] == "number" || syntax_tokens1[ii - 1] == "ID" || syntax_tokens1[ii - 1] == "String" || syntax_tokens1[jj] == "expression"))
				{
					syntax_tokens2[jj] = "expression";
					ii++;
				}
				else
				{
					syntax_tokens2[jj] = "expression error";
					ii++;
				}
			}
			else
			{
				jj++;
				syntax_tokens2[jj] = syntax_tokens1[ii];
				num2++;
			}
		}

		/// --------------------------- preprocess tokens for conditions ---------------------------
		int jjj = 0, iii = 0, num3 = 0;
		string* syntax_tokens3 = new string[num2];
		syntax_tokens3[jjj] = syntax_tokens2[iii];
		iii++;
		num3++;
		for (; iii < num2; iii++)
		{
			if (syntax_tokens2[iii] == "comparison operator")
			{
				if ((syntax_tokens2[iii + 1] == "expression" || syntax_tokens2[iii + 1] == "number" || syntax_tokens2[iii + 1] == "ID" || syntax_tokens2[iii + 1] == "String") && (syntax_tokens2[iii - 1] == "number" || syntax_tokens2[iii - 1] == "ID" || syntax_tokens2[iii - 1] == "String" || syntax_tokens2[iii - 1] == "expression"))
				{
					syntax_tokens3[jjj] = "condition";
					iii++;
				}
				else
				{
					syntax_tokens3[jjj] = "condition error";
					iii++;
				}
			}
			else
			{
				jjj++;
				syntax_tokens3[jjj] = syntax_tokens2[iii];
				num3++;
			}
		}


		/// --------------------------- preprocess tokens for read,write and assignment statements ---------------------------
		int jjjj = 0, iiii = 0, num4 = 0;
		string* syntax_tokens4 = new string[num3];
		syntax_tokens4[jjjj] = syntax_tokens3[iiii];
		iiii++;
		num4++;
		for (; iiii < num3; iiii++)
		{
			if (syntax_tokens3[iiii] == "equal operator") // assignment statement
			{
				if ((syntax_tokens3[iiii + 1] == "expression" || syntax_tokens3[iiii + 1] == "number" || syntax_tokens3[iiii + 1] == "ID" || syntax_tokens3[iiii + 1] == "String") && (syntax_tokens3[iiii - 1] == "ID") && (syntax_tokens3[iiii + 2] == "symbol semicolon"))
				{
					syntax_tokens4[jjjj] = "assign statement";
					iiii += 2;
				}
				else
				{
					syntax_tokens4[jjjj] = "assign statement error";
					iiii++;
				}
			}
			else if (syntax_tokens3[iiii] == "reserved word 'read'" || syntax_tokens4[jjjj] == "reserved word 'read'") // read input statement
			{
				if (syntax_tokens4[jjjj] == "reserved word 'read'")
				{
					jjjj--;
					num4--;
					iiii--;
				}
				if (syntax_tokens3[iiii + 1] == "ID" )
				{
					jjjj++;
					num4++;
					syntax_tokens4[jjjj] = "read statement";
					iiii++;
				}
				else
				{
					jjjj++;
					num4++;
					syntax_tokens4[jjjj] = "read statement error";
					iiii++;
				}
			}
			else if (syntax_tokens3[iiii] == "reserved word 'write'" || syntax_tokens4[jjjj] == "reserved word 'write'") // write statement
			{
				if (syntax_tokens4[jjjj] == "reserved word 'write'")
				{
					jjjj--;
					num4--;
					iiii--;
				}
				if (syntax_tokens3[iiii + 1] == "expression" || syntax_tokens3[iiii + 1] == "number" || syntax_tokens3[iiii + 1] == "ID" || syntax_tokens3[iiii + 1] == "String")
				{
					jjjj++;
					num4++;
					syntax_tokens4[jjjj] = "write statement";
					iiii++;
				}
				else
				{
					jjjj++;
					num4++;
					syntax_tokens4[jjjj] = "write statement error";
					iiii++;
				}
			}
			else if (syntax_tokens3[iiii] == "comma") // comma 
			{
				if (syntax_tokens4[jjjj] == "read statement")
				{
					if (syntax_tokens3[iiii + 1] == "ID")
					{
						iiii++;
					}
					else
					{
						syntax_tokens4[jjjj] = "read statement error";
					}
				}
				else if (syntax_tokens4[jjjj] == "write statement")
				{
					if (syntax_tokens3[iiii + 1] == "expression" || syntax_tokens3[iiii + 1] == "number" || syntax_tokens3[iiii + 1] == "ID" || syntax_tokens3[iiii + 1] == "String")
						iiii++;
					else
					{
						syntax_tokens4[jjjj] = "write statement error";
					}
				}
				else
				{
					jjjj++;
					num4++;
					syntax_tokens4[jjjj] = "comma error";
					iiii++;
				}
			}
			else
			{
				jjjj++;
				syntax_tokens4[jjjj] = syntax_tokens3[iiii];
				num4++;
			}
		}

		// -------------------------------------- semicolon processing -----------------------------------

		int i5 = 0, j5 = 0, num5 = 0;
		string* syntax_tokens5 = new string[num4];
		for (; i5 < num4; i5++)
		{
			if (syntax_tokens4[i5] == "read statement")
			{
				if (syntax_tokens4[i5 + 1] == "symbol semicolon")
				{
					syntax_tokens5[j5] = syntax_tokens4[i5];
					i5++;
					j5++;
					num5++;
				}
				else 
				{
					syntax_tokens5[j5] = "read statement error";
					j5++;
					num5++;
				}
				
			}
			else if (syntax_tokens4[i5] == "read statement error")
			{
				if (syntax_tokens4[i5 + 1] == "symbol semicolon")
				{
					syntax_tokens5[j5] = syntax_tokens4[i5];
					i5++;
					j5++;
					num5++;
				}
				else
				{
					syntax_tokens5[j5] = syntax_tokens4[i5];
					j5++;
					num5++;
				}

			}
			else if (syntax_tokens4[i5] == "write statement")
			{
				if (syntax_tokens4[i5 + 1] == "symbol semicolon")
				{
					syntax_tokens5[j5] = syntax_tokens4[i5];
					i5++;
					j5++;
					num5++;
				}
				else
				{
					syntax_tokens5[j5] = "write statement error";
					j5++;
					num5++;
				}
			}
			else if (syntax_tokens4[i5] == "write statement error")
			{
				if (syntax_tokens4[i5 + 1] == "symbol semicolon")
				{
					syntax_tokens5[j5] = syntax_tokens4[i5];
					i5++;
					j5++;
					num5++;
				}
				else
				{
					syntax_tokens5[j5] = syntax_tokens4[i5];
					j5++;
					num5++;
				}
			}
			else
			{
				syntax_tokens5[j5] = syntax_tokens4[i5];
				j5++;
				num5++;
			}
		}

		/*cout << endl << endl << "tokens5 num5 = " << num5 << endl;
		for (int g = 0; g < num5; g++)
			cout << "=>" << syntax_tokens5[g] << endl;*/

		// -------------------------------------- syntax processing -----------------------------------
		string f1 = "reserved word 'if'conditionreserved word 'then'reserved word 'end'";
		string f2 = "reserved word 'if'conditionreserved word 'then'reserved word 'if'conditionreserved word 'then'reserved word 'end'reserved word 'end'";
		string f3 = "reserved word 'if'conditionreserved word 'then'reserved word 'if'conditionreserved word 'then'reserved word 'if'conditionreserved word 'then'reserved word 'end'reserved word 'end'reserved word 'end'";
		string f4 = "reserved word 'repeat'reserved word 'until'condition";
		string f5 = "reserved word 'repeat'reserved word 'repeat'reserved word 'until'conditionreserved word 'until'condition";
		string f6 = "reserved word 'repeat'reserved word 'repeat'reserved word 'repeat'reserved word 'until'conditionreserved word 'until'conditionreserved word 'until'condition";
		string f7 = "reserved word 'if'conditionreserved word 'then'reserved word 'repeat'reserved word 'until'conditionreserved word 'end'";
		string f8 = "reserved word 'repeat'reserved word 'if'conditionreserved word 'then'reserved word 'end'reserved word 'until'condition";
		string ferrors = "";
		string f = "";
		for (int i = 0; i < num5; i++)
		{
			if (syntax_tokens5[i] == "reserved word 'if'" || syntax_tokens5[i] == "reserved word 'then'" || syntax_tokens5[i] == "reserved word 'end'" || syntax_tokens5[i] == "reserved word 'until'" || syntax_tokens5[i] == "reserved word 'repeat'")
			{
				if (syntax_tokens5[i] != "reserved word 'then'")
					code_lines++;
				if ((syntax_tokens5[i] == "reserved word 'if'" || syntax_tokens5[i] == "reserved word 'until'") && syntax_tokens5[i + 1] == "condition")
				{
					
					f += syntax_tokens5[i];
					f += syntax_tokens5[i + 1];
					i++;
				}
				else if ((syntax_tokens5[i] == "reserved word 'if'" || syntax_tokens5[i] == "reserved word 'until'") && syntax_tokens5[i + 1] == "condition error")
				{
					f += syntax_tokens5[i];
					f += "condition";
					if (syntax_tokens5[i] == "reserved word 'if'")
					{
						errors += "Error: " + syntax_tokens5[i + 1] + " at line " + to_string(code_lines) + "\n";
						ferrors = "f_statement";
					}
					else
					{
						errors += "Error: " + syntax_tokens5[i + 1] + "  at " + to_string(code_lines) + "\n";
						ferrors = "repeat_statement";
					}
					i++;
				}
				else if ((syntax_tokens5[i] == "reserved word 'if'" || syntax_tokens5[i] == "reserved word 'until'") && syntax_tokens5[i + 1] != "condition error" && syntax_tokens5[i + 1] != "condition")
				{
					f += syntax_tokens5[i];
					f += "condition";
					if (syntax_tokens5[i] == "reserved word 'if'")
						errors += "Error: syntax error at line " + to_string(code_lines) + " ; if must be folowed by condition." + "\n";
					else
						errors += "Error: syntax error  at line " + to_string(code_lines) + " ; until must be folowed by condition" + "\n";
					i++;
				}
				else
				{
					f += syntax_tokens5[i];
				}
			}
			else if (syntax_tokens5[i] == "condition error" || syntax_tokens5[i] == "assign statement error" || syntax_tokens5[i] == "read statement error" || syntax_tokens5[i] == "write statement error" || syntax_tokens5[i] == "expression error" || syntax_tokens5[i] == "Error")
			{
				code_lines++;
				errors += "Error: syntax error ; " + syntax_tokens5[i] + " at line " + to_string(code_lines) + " \n";
			}
			else if (syntax_tokens5[i] == "condition" && syntax_tokens5[i - 1] != "reserved word 'if'" && syntax_tokens5[i - 1] != "reserved word 'until'")
			{
				code_lines++;
				errors += "Error: condition can not be used as statement at line"+ to_string(code_lines) +"\n" ;
				
			}
			else
				code_lines++;
		}

		if (!f.empty())
			if (f != f1 && f != f2 && f != f3 && f != f4 && f != f5 && f != f6 && f != f7 && f != f8)
				errors += "Error: syntax error " + ferrors + "\n";

		cout << "lines: " << code_lines << endl;
		if (errors != "")
			cout << endl << errors << endl;
		else
		{
			errors = "Accepted Synyax ";
			cout << endl << errors << endl;
		}
	}
};