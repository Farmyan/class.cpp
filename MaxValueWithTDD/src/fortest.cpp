int MatrixMaxValue(int array[], int size)
{
 int index = 0;
 int max = array[0];
  while(index<size)
  {
    if(array[index]>max)
    {
         max = array[index];
    } 
    index++;
 }
 return max;
}


//Կարելի է գրել loop-ով
// for(index = 0; index<size;index++)
// {
//     if(max<array[index])
//     {
//         max = array[index];
//     }
// }