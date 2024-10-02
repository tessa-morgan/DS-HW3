typedef int ordered<>;

program RPC_SYSTEM_PROGRAM {
    version RPC_SYSTEM_VERS {
        void APPEND(ordered) = 1;
        int QUERY(int) = 2;
        void REMOVE(int) = 3;
    } = 1;
} = 0x31234567;