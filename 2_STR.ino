class Str {
  public:

    /// @brief checks if char array from indBegin to indEnd consists only of numbers
    static bool isANumber(const char* str, int indBegin, int indEnd);

    /// @brief converts char array from indBegin to indEnd into integer
    /// @return conversion result
    ///
    /// @detalied does not check if char values are valid
    static int charToInt(const char* str, int indBegin, int indEnd);

    /// @brief checks if command is included in first indexes of str
    /// @return true if command is included
    ///         false if command is not included
    ///
    /// @delailed compares strings index by index
    ///           finishes when command or str ends 
    static bool compareCommandAndString(char* command, char* str);
  private:
  Str(){}  
};


static bool Str::isANumber(const char* str, int indBegin, int indEnd)
{
  for(int i=indBegin; i<indEnd; i++){
    if(!isdigit(str[i]))
      return false;
  }
  return true;
}


static int Str::charToInt(const char* str, int indBegin, int indEnd)
{
  char* s = (char*)malloc((indEnd-indBegin+1)*sizeof(char));
  for(int i=0; i<indEnd-indBegin; i++){
    s[i] = str[indBegin+i];
  }
  s[indEnd-indBegin] = 0;
  int val = atoi(s);
  free(s);
  return  val;
}
 
static bool Str::compareCommandAndString(char* command, char* str)
{
  bool same = true;
  for(int i=0; i<1000; i++){
    if(command[i]==0)
      break;
    if(str[i]==0){
      same=false;
      break;
    }
    if(command[i]!=str[i])
      same = false;
  }

  return same;
}
