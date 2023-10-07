#include"extras.h"

void advancedEncrypt(char text[]){
    char pass[10];

    printf("Input password (Capital letters only, maximum 10 letters)\n");
    scanf("%s", pass);

    int text_length = strlen(text);
    int pass_length = strlen(pass);

    for (int i = 0, j = 0; i < text_length; i++) {
        char current_char = text[i];

        if (current_char >= 'A' && current_char <= 'Z') {
            // Encrypt or decrypt the character based on the password
            char key = pass[j] - 'A' + 1;

            if (current_char >= 'A' && current_char <= 'Z') {
                // Encryption
                text[i] = ((current_char - 'A' + key) % 26) + 'A';
            }

            // Move to the next character in the password
            j = (j + 1) % pass_length;
        }
    }

    printf("%s\n", text);
}





void vigenere_encrypt(){

    char text[MAXCHAR], filename[MAXCHAR], aux;
    int input;


    FILE *f;

    printf("Do you want to input text in console(1) or get it from a file(2)?\n");
    scanf("%d", &input);

    if (input == 1){
        printf("Enter your text\n");
        getchar();
        fgets(text, MAXCHAR, stdin);
        advancedEncrypt(text);

    } else if(input == 2){
        printf("Enter name of the file:\n");
        scanf("%s", filename);
        if(((f) = fopen(filename, "r")) == NULL){
        	printf("ERROR: File not found\n");
    	} else {
            while(!feof(f)){
            fgets(text, MAXCHAR, f);
            //fscanf(f, "%s", aux);
            advancedEncrypt(text);
            }
    	}


    } else {
        printf("ERROR: Returning to main menu\n\n");
    }

}




void rotateLetters(char text[]){
int i, j;

for(int j = 1; j <= 26; j++){
            char decryptedText[MAXCHAR]; // New array to store decrypted text

            strcpy(decryptedText, text); // Copy original text to decryptedText

            printf("%d: ", j);


            for(int i = 0; i < strlen(decryptedText) - 1; i++){
                /*if ((decryptedText[i] >= 'A' && decryptedText[i] <= 'Z') || (decryptedText[i] >= 'a' && decryptedText[i] <= 'z')){
                    char base = (decryptedText[i] >= 'A' && decryptedText[i] <= 'Z') ? 'A' : 'a';
                    decryptedText[i] = (decryptedText[i] - base - j + 26) % 26 + base;
                }*/


                if (decryptedText[i] < 65 || decryptedText[i] > 90){
                    continue;
                }

                if (decryptedText[i] - j < 65){
                    decryptedText[i] = 91 - (65 - (decryptedText[i] - j));
                } else {
                    decryptedText[i] = decryptedText[i] - j;
                }
            }
            printf("%s\n", decryptedText);
        }


}

void decryptText(){
    char text[MAXCHAR], filename[MAXCHAR];
    int input;

    FILE *f;

    printf("Do you want to input text in console(1) or get it from a file(2)?\n");
    scanf("%d", &input);

    if (input == 1){
        printf("Enter your text:\n");
        getchar();
        fgets(text, MAXCHAR, stdin);

        printf("%s\n", text);
        printf("\n");

        rotateLetters(text);



    } else if(input == 2){
        printf("Enter name of the file:\n");
        scanf("%s", filename);
        if(((f) = fopen(filename, "r")) == NULL){
        	printf("ERROR: File not found\n");
    	} else {
            while(!feof(f)){
            //getchar();
            fgets(text, MAXCHAR, f);
            rotateLetters(text);
            }
    	}


    } else {
        printf("ERROR: Returning to main menu\n\n");
    }



}

void processEncrypt(char text[]){
    int num, i;

    printf("Input a number from 1 to 25\n");
    scanf("%d", &num);

    if (num > 0 && num < 26){


        for(int i = 0; i < strlen(text) - 1; i++){
            if (text[i] < 65 || text[i] > 90){
                i++;
            }

            if (text[i] - num < 65){
                text[i] = 91 - (65 - (text[i] - num));

            } else if (text[i] - num >= 65){
                text[i] = text[i] - num;
            }
        }

        printf("%s\n", text);

    } else {
        printf("ERROR\n");
    }


}

void encryptText(){
    char text[MAXCHAR], filename[MAXCHAR], aux;
    int input;


    FILE *f;

    printf("Do you want to input text in console(1) or get it from a file(2)?\n");
    scanf("%d", &input);

    if (input == 1){
        printf("Enter your text\n");
        getchar();
        fgets(text, MAXCHAR, stdin);
        processEncrypt(text);

    } else if(input == 2){
        printf("Enter name of the file:\n");
        scanf("%s", filename);
        if(((f) = fopen(filename, "r")) == NULL){
        	printf("ERROR: File not found\n");
    	} else {
            while(!feof(f)){
            fgets(text, MAXCHAR, f);
            //fscanf(f, "%s", aux);
            processEncrypt(text);
            }
    	}


    } else {
        printf("ERROR: Returning to main menu\n\n");
    }

}


int main(){
    int option = 0;

    printf("Welcome to Caesar/Vigenère cipher program\n");

    do{
    printf("1 - encrypt text using caesar cipher\n");
    printf("2 - decrypt caesar cipher\n");
    printf("3 - info about Caesar cipher\n");
    printf("4 - encrypt text using Vigenère cipher\n");
    printf("5 - decrypt Vigenère cipher\n");
    printf("6 - info about Vigenère cipher\n");
    printf("7 - exit\n");
    printf("Choose an option\n");
    scanf("%d", &option);

    if (option == 1){
    encryptText();

    } else if (option == 2){
    decryptText();

    } else if (option == 3){
    printf("In cryptography, a Caesar cipher, also known as Caesar's cipher, the shift cipher, Caesar's code, or Caesar shift, is one of the simplest and most widely known encryption techniques. It is a type of substitution cipher in which each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet. For example, with a left shift of 3, D would be replaced by A, E would become B, and so on. The method is named after Julius Caesar, who used it in his private correspondence\n");
    } else if (option == 4){
    vigenere_encrypt();
    } else if (option == 5){


    } else if (option == 6){
        printf("The Vigenère cipher is a method of encrypting alphabetic text where each letter of the plaintext is encoded with a different Caesar cipher, whose increment is determined by the corresponding letter of another text, the key.\n");
        printf("For example, if the plaintext is attacking tonight and the key is OCULORHINOLARINGOLOGY, then\n");
        printf("the first letter a of the plaintext is shifted by 14 positions in the alphabet (because the first letter O of the key is the 14th letter of the alphabet, counting from 0), yielding o;\n");
        printf("the second letter t is shifted by 2 (because the second letter C of the key means 2) yielding v;\n");
        printf("the third letter t is shifted by 20 (U) yielding n, with wrap-around;\n");
        printf("and so on; yielding the message ovnlqbpvt eoeqtnh. If the recipient of the message knows the key, they can recover the plaintext by reversing this process.\n");
    }

    } while(option != 7);
}
