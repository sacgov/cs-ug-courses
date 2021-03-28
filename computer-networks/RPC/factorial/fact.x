struct for_factorial{
    int num;
};

program FACT{
    version FACT_1 {
        int fact_calc(for_factorial)=1;
    } = 1;
} = 0x1fffffff;
