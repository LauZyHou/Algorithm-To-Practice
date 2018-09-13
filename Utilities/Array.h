#pragma once

//在start和end中随机找一个数,在长为length的data数组中以此下标为界
//划分整个数组,使比它(所对应的数)小的数都在其左边,>=它的在右边 
int Partition(int data[], int length, int start, int end);
