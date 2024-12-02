int main() {
 int i, c=" &";
 char com[100];
 scanf("%s", com);
 while(strcmp(com, "end")!=0) {
  strcat(com,c);
  system(com);
  scanf("%s", com);
 }
 return 0;
}
    