// -1 = lose, 0 = draw, 1 = win
int didIWin(int myPick, int otherPick, int numChoices)
{
  int result = (myPick - otherPick + numChoices) % numChoices; // Make sure this doesn't mess up with overflows
  
  int partition = numChoices / 2;
  if(result == partition && numChoices % 2 == 0)
    result = 0;
  
  if(result == 0)
    return 0;
  else if(result > partition)
    return -1;
  else
    return 1;
}
