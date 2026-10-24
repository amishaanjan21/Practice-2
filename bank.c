#include <stdio.h>
double deposit(double balance, double amount);
double withdraw(double balance, double amount);
double calculateInterest(double principal, double rate, double time);
int readDouble(double *value);
int main(){
char name[50];
double balance, amount, rate, time, interest;
int choice;
printf("Enter account holder's name: ");
scanf(" %49[^\n]", name);
do{
printf("Enter opening balance: ");
if (!readDouble(&balance)){
balance = -1;
}
if (balance < 0){
printf("Invalid balance. Enter a number that is 0 or more.\n");
}
}while(balance < 0);
do{
printf("\n1. Deposit\n2. Withdraw\n3. Check balance\n4. Calculate interest\n5. Exit\n");
printf("Enter choice: ");
if (scanf("%d", &choice) != 1){
printf("Please enter a number from 1 to 5.\n");
while (getchar() != '\n');
choice = 0;
continue;
}
switch (choice){
case 1:
printf("Enter deposit amount: ");
if (!readDouble(&amount) || amount <= 0){
printf("Invalid amount.\n");
}
else{
balance = deposit(balance, amount);
printf("New balance: %.2f\n", balance);
}
break;
case 2:
printf("Enter withdrawal amount: ");
if (!readDouble(&amount) || amount <= 0){
printf("Invalid amount.\n");
}
else if (amount > balance){
printf("Insufficient balance.\n");
}
else{
balance = withdraw(balance, amount);
printf("New balance: %.2f\n", balance);
}
break;
case 3:
printf("%s's balance: %.2f\n", name, balance);
break;
case 4:
printf("Enter annual rate: ");
if (!readDouble(&rate) || rate <= 0){
printf("Invalid rate.\n");
break;
}
printf("Enter time (years): ");
if (!readDouble(&time) || time <= 0){
printf("Invalid time.\n");
break;
}
interest = calculateInterest(balance, rate, time);
printf("Simple interest: %.2f\n", interest);
break;
case 5:
printf("Exiting.\n");
break;
default:
printf("Invalid choice.\n");
}
}while(choice!=5);
return 0;}
double deposit(double balance, double amount){
return balance + amount;}
double withdraw(double balance, double amount){
return balance - amount;}
double calculateInterest(double principal, double rate, double time){
return (principal * rate * time)/100;}
int readDouble(double *value){
if (scanf("%lf", value) != 1){
while (getchar() != '\n');
return 0;}
return 1;}