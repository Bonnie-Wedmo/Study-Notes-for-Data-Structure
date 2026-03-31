//2026.3.31
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    //因为size不能直接读取，需要我先定义一个
    *returnSize = 2;
    //先给结果分配一个栈
   int* result = (int*)malloc(2*sizeof(int));//因为结果是int类型的，所以分一个int大小的

   for(int i = 0; i<numsSize;i++){
        for (int j = i+1;j<numsSize;j++)
        {
            if (nums[i]+nums[j]==target)
                {
                    result[0]=i;
                    result[1]=j;
                    return result;
                }
        }
   }

   return result;
}
