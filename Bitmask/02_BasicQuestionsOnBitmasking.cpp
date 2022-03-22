/*
    *************** Basic Question on Bitmasking **********

############### Q1 ##### find unique element

    => 1 1 2 2 3 3 4

    Xor ( ^ ) has special property to canceling the same element
    1 ^ 1 => 0
    ( 1^1^2^2^3^3^4) => 4



################### Q2 ######### 2-s compliment
    computer can not subtract
    5 => 00000101   flip all the bit
   -5=>  11111010
               +1
    --------------
        11111011
    -5  11111010
    --------------
        00000101

################### Q3 ##########
    odd or even
    5 => 00000101
               &1
    -------------
                1 => odd
                0 => even

    if(n & 1)
    {
        cout << odd;
    }
    else{
        cout << even;
    }


################## Q4 ##############
    min number of bit we have to change that
    convert a -> b
     a, b
     a=11, b=15

     a=> 1011
     b=> 1111
  a^b => 0100

    count set bit (1) => 1


############ Q5 ##########
    count the number of set bits

    cnt = 0
    while( n > 0)
    {
        cnt += ( n & 1);

        n = n >> 1;
    }


################ Q6 #############
    we have to remove last set bit
    n = 13
    sol => n & (n-1)

    how:
    13 => 1101
    12 => 1100
    ----------
         1100 (output)

    More continue
    12 => 1100
    11 => 1011
    ----------
          1000 output

############### Q7 ###############
    swapping or XOR swapping

    temp = a
    a = b
    b = temp

    a=5, b=7

    a = a^b => 5^7
    b = b^a => 7^5^7;
    a = a^b => 5^7^5

##################### Q8 #############3
    Extract ith bit

          3210
    13 => 1101   2nd bit
          0100   (1 << 2) mask
        -------
          0100



        n & ( 1 << i) i th bit Extract


#################### Q9 ############
    change the i th bit
    13 => 1101
          0100   (1 << 2) mask
        ---------
    or   1001

  =>  n | ( 1 << 2)   change the i th bit


################## Q10 #############
    Clearing i th bit  1 -> 0

    13 => 1101
        & 1011      ~0100    ~( 1 << 2) 2bit mask
        ---------
          1001
  n



*/
