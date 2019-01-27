#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

class node {
public:
    string data;
    node* left;
    node* right;
};
// for debugging
// void print_preorder(node* root){
//     if(root){
//         cout<< root->data << endl;
//         print_preorder(root->left);
//         print_preorder(root->right);
//     }
// }
void read_preorder(node* tree, ifstream &fs){
    string type;
    string data;
    fs >> type;
    fs.ignore();
    getline(fs,data);
    tree->data = data;
    if(type=="#A") return;
    else{
        tree->left = new node;
        read_preorder(tree->left,fs);
        
        tree->right = new node;
        read_preorder(tree->right,fs);
    }
}

node* read_game_tree(){
    ifstream fs("animal.txt");
    node* root = new node;
    read_preorder(root,fs);
    return root;
}

void delete_game_tree(node* root){
    if(root!=NULL){
        delete_game_tree(root->left);
        delete_game_tree(root->right);
        delete root;
    }
}

void write_preorder(node* tree, ofstream &fs){
    if(tree!=NULL){
        if(tree->left && tree->right){
            fs << "#Q " << tree->data << endl;
            write_preorder(tree->left, fs);
            write_preorder(tree->right, fs);
        }
        else{
            fs << "#A " << tree->data << endl;
        }
        
    }
}

void save_game_tree(node* root){
    ofstream fs("animal.txt");
    write_preorder(root, fs);
    
}

void play_game(node* root){
    queue<string> history;
    node* current = new node;
    current = root;
    while(current != NULL && (current->left && current->right)){
        cout << current->data << " " << "(y/n) :: ";
        string response;
        while(response[0] != 'y' && response[0]!='n'){
            cin >> response;
        }
        if(response[0] == 'y'){
            history.push(current->data + " YES");
            current = current->left;
        }
        else if(response[0]=='n'){
            history.push(current->data + " NO");
            current = current->right;
        }
    }
    cout << current->data << " " << "(y/n) :: ";
    string response;
    while(response[0] != 'y' && response[0]!='n'){
        cin >> response;
    }
    if(response[0] == 'y'){
        cout << "YAY! I guessed your animal!\n\n";
    }
    else{
        history.push(current->data + " NO");
        cout << "BOO! I don't know!" << endl << endl << endl;
        cout << "Would you like to expand the game tree? (y/n) :: ";
        string response;
        while(response[0] != 'y' && response[0]!='n'){
            cin >> response;
        }
        if(response[0]=='y'){
            cout << "I asked the following:\n";
            while(!history.empty()){
                cout << history.front() << endl;
                history.pop();
            }
            cout << "Enter a new animal in the form of a question,\ne.g., 'Is it a whale?' :: ";
            string new_animal;
            cin.ignore(); // catch empty enter-key from cin >> in line 108
            getline(cin,new_animal);
            
            cout << "Now enter a question for which the answer is 'yes' for your new\nanimal, and which does not contradict your previous answers :: ";
            string new_question;
            getline(cin,new_question);
            
            string node_to_move = current->data;
            current->data = new_question;
            
            current->left = new node;
            current->left->data = new_animal;
            
            current->right = new node;
            current->right->data = node_to_move;
            
        }
        else{
            cout << "\n\n\nOk then.....\n\n\n\n";
        }
             
    }
}

int main() {
	node* root = read_game_tree();
// 	print_preorder(root);
	if (root == NULL) return -1;

	while (true) {
	
		int choice;
		
		cout << "Welcome to 20 questions!" << endl;
		cout << "  1) Play the game" << endl;
		cout << "  2) Save the game file" << endl;
		cout << "  3) Quit" << endl;
		cout << "Please make your selection: ";

		cin >> choice;

		switch (choice) {
		case 1:
			play_game(root);
			break;
		case 2:
			save_game_tree(root);
			break;
		case 3:
			break;
		default:
			cout << "Sorry, I don't understand." << endl << endl;
		}
		if (choice == 3) break;
	}
	
	delete_game_tree(root);
	return 0;
}