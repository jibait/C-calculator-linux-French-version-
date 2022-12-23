#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 25

double calculatrice(double,char,double);

int main(){
    int i = 0;
    double result = 0;
    printf("************************************************\n");
    printf("ecrire sous la forme x + y avec les espaces pour avoir un resultat\n");
    printf("flush pour nettoyer le terminal\n");
    printf("quit pour quitter\n");
    printf("************************************************\n");
    char *text = calloc(1,1), buffer[BUFFER];
    printf("%d> ",i);
    i++;
    while( fgets(buffer, BUFFER , stdin)){
        char * val_1;
    	char * val_2;
    	char * op;
    	if (!strncmp(buffer, "quit",strlen("quit"))){
    		break;
    	}
    	if (!strncmp(buffer, "flush",strlen("flush"))){
    		system("clear");
    	}
    	else{
	    	text = realloc( text, strlen(text)+1+strlen(buffer) );
	    	if( text ){ 
	    		strcat(text, buffer);
			val_1 = strtok(buffer," ");
	    		op = strtok(NULL," ");
	    		val_2 = strtok(NULL," ");
	    	}
	    	if ((!strncmp(op, "/",strlen("/")) || (!strncmp(op, "%",strlen("%")))) && !strncmp(val_2, "0",strlen("0"))){
	    		printf("division par zero impossible! \n");
	    	}
	    	else{
			if (!strncmp(val_1, "res",strlen("res"))){
				double nb2 = atof(val_2);
				result = calculatrice(result, *op, nb2);
				printf("%d> ",i);
		    			i++;
		    	}
		    	else{
		    		if(!strncmp(val_2, "res",strlen("res"))){
		    			double nb1 = atof(val_1);
		    			result = calculatrice(nb1, *op, result);
		    			printf("%d> ",i);
		    			i++;
		    		}
		    		else{
		    			double nb1 = atof(val_1); 
		    			double nb2 = atof(val_2);
		    			result = calculatrice(nb1, *op, nb2);
		    			printf("%d> ",i);
		    			i++;
		    		}
		    	}
		} 
	}  
    }
    return 0;
}

double calculatrice(double value_1, char operator, double value_2){
    double result = 0;
    switch (operator)
    {
    case '+':
        result = value_1 + value_2;
        printf("resultat : %.2f\n",result);
        return result;
        break;

    case '-':
        result = value_1 - value_2;
        printf("resultat : %.2f\n",result);
        return result;
        break;

    case '*':
        result = value_1 * value_2;
        printf("resultat : %.2f\n",result);
        return result;
        break;
    
    case '/':
        result = value_1 / value_2;
        printf("resultat : %.2f\n",result);
        return result;
        break;

    case '%':
        result = (int)value_1 % (int)value_2;
        printf("resultat : %.2f\n",result);
        return result;
        break;
    default:
        break;
    }
    return 0;
}
