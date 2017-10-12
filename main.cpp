#include <iostream>
#include <fstream>
#include <cstring>
#define N 250051

struct entry
{
	bool hashed=false;
	char *word;
	char *part_of_speech;
	char *definition;
//	entry* chain=NULL;

};



int hash(std::string str)
{
	std::string temp = str;
	int total = 0;
	int factor1 = 2;
	int factor2 = 3;
	for(int i = 0; i < temp.size(); i++)
	{
		if(temp[i] == 32) temp[i] = 95;

		total += temp[i]*factor2;
		total *= factor2;
		total <<=2;

		factor1 *= factor2;
		factor2 = factor1 + 1;
	}
	if(total < 0 ) total *= -1;
	return total%N;
}


int main()
{
	for(int h = 0; h < 1; h++)
	{
	
	entry htable[N];
	std::fstream words("d2.txt", std::ios::in);
	std::fstream keys("keys.txt", std::ios::out);
	int table_size =0;	

	//iterate through the dictionary file to get the entire lines
	if(words)
	{


		for(int i = 0; words; i++)
		{
			char *str = new char[530];
			if(words)
			{
				
				words.getline(str,530,'\n');//to read in the whole line, I put it here to clear to next line

			}

			std::string line = str;
			int first_pipe = line.find_first_of('|');
			int second_pipe = line.find_first_of('|',first_pipe+1);

			std::string word = line.substr(0,first_pipe);
			std::string part_of_speech = line.substr(first_pipe+1, second_pipe-first_pipe-1);
			std::string def = line.substr(second_pipe+1, line.size()-second_pipe-1);
			int key = hash(word);
			



			int collisions =0;
		//	switch(h)
		//	{
		//		//linear probing
		/*		case 0:*/	while(htable[key].hashed)
					{
						key = (key + collisions++)%N;
					}/*
					break;
				//quadratic probing
				case 1:	while(htable[key].hashed)
					{
						key = (key + collisions*collisions++)%N;
					}	
					break;
				//separate chaining
				case 2: break;

				//double hashing
				case 3: while(htable[key].hashed)
					{
						key = hash(std::to_string(key));
						collisions++;
					}
					break;
				default: break;

			
			}*/
			keys<<key<<'\n';

			//if(h!=2)
			//{
			htable[key].word = new char[word.size()];
			strncpy(htable[key].word, word.c_str(), word.size());
			std::cout<< htable[key].word << '|';

	
			htable[key].part_of_speech = new char[part_of_speech.size()];
			strncpy(htable[key].part_of_speech , part_of_speech.c_str(),part_of_speech.size());
			std::cout<< htable[key].part_of_speech << '|';


			htable[key].definition = new char[def.size()];
			strncpy(htable[key].definition,def.c_str(), def.size() );
			std::cout<< htable[key].definition << '\n';
			
//			htable[key].chain = NULL;
			table_size++; std::cout<<table_size<<'\n';
			htable[key].hashed = true;

			//}
			//else
			//{
/* 
				 entry* temp = &htable[key];

				if(temp->hashed)
				{
				 while(temp->chain)
				 {
				       temp =temp->chain;
				       collisions++;
				 }
				 temp = temp->chain;
				}
				else
				{
					temp->chain = temp;
				}

			temp->chain->word = new char[word.size()];
				strncpy(temp->chain->word, word.c_str(), word.size());	
			temp->chain->part_of_speech = new char[part_of_speech.size()];
				strncpy(temp->chain->part_of_speech , part_of_speech.c_str(),part_of_speech.size());
			temp->chain->definition = new char[def.size()];
				strncpy(temp->chain->definition,def.c_str(), def.size() );

				temp->chain->chain = NULL;
				temp->chain->hashed = true;
*/			//}

			
		}

	}
	string search;
	std::cout<<"enter word: ";std::cin>>search;
	
	words.close();
	}

	std::fstream ofile("keys.txt", std::ios::out);
	
	
	ofile.close();

	
	return 0;

}
