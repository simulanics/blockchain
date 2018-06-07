// Copyright (c) 2011-2016 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
//TODO Currency-specific address prefix
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x1A2B; // addresses start with "Vd"
//TODO Choose maturity period for your currency
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 60;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

//TODO Specify total number of available coins
//TODO ((uint64_t)(-1)) equals to 18446744073709551616 coins
//TODO or you can define number explicitly UINT64_C(858986905600000000)
const uint64_t MONEY_SUPPLY                                  = UINT64_C(858986905600000000);
const unsigned EMISSION_SPEED_FACTOR                         = 23;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

//TODO Define number of blocks for block size median calculation
const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 20000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
//TODO Define number of digits
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
//TODO Define minimum fee for transactions
const uint64_t MINIMUM_FEE                                   = INT64_C(100000);     // pow(10, 5)
const uint64_t DEFAULT_DUST_THRESHOLD                        = MINIMUM_FEE;
const uint64_t COIN                                          = UINT64_C(100000000);  // pow(10, 8)

//TODO Define preferred block's target time
const uint64_t DIFFICULTY_TARGET                             = 60; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
//TODO There are options to tune CryptoNote's difficulty retargeting function.
//TODO We recommend not to change it.
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        =  20 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

//TODO Put here the name of your currency
const char     CRYPTONOTE_NAME[]                             = "monetaverde";
const char     GENESIS_COINBASE_TX_HEX[]                     = "013c01ff0001bea8e0bbfd02029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101a557bdc5edbc20a34e449180b421225c9d4588923b18698519eb72f3ea64dd1b";

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

//TODO This port will be used by the daemon to establish connections with p2p network
const int      P2P_DEFAULT_PORT                              = 26080;
//TODO This port will be used by the daemon to interact with simlewallet
const int      RPC_DEFAULT_PORT                              = 26081;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "db9eabe971890012a4071a96468155c2c360f80d18e73caa97bffd3b7381eed7";

//TODO Add here your network seed nodes
const std::initializer_list<const char*> SEED_NODES = {
        "18.204.131.141:26080",
        "34.230.163.166:26080",
        "52.20.180.208:26080"
};


struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
            {79000,  "5944de21dda90a33528d71543f86ca4390b3355634b1449a19926e27e102d859"},
            {140000, "d5478735480280e12dad8769ce6f6efba833c063d3ccb1b836b835be141dbd4e"},
            {200000, "23f18774eee12a43c80d7162fba4d5fb10290128f31890a7cd0ff6c4e2948277"},
            {230580, "59743b0ba05ddea448fb220e8237d0f7e579e9784fb05db7446aa14043ce9f74"},
            {260000, "f17cf75dcdcfdd3e4984bc821e754b40f47f0c618c123552596190d29b1418d7"},
            {300000, "81084b07b5cb7977442cc7e4bacc27d7a7d90e422645f080b7da2038e1d7b7c2"},
            {390285, "e19b40dcd833f5b45477304f6fa364834a3185545a7b54c2d74eceb758d09848"},
            {417000, "e8e662cf785fb0cb9ebabf8ee9c494c6c5d4e9167577dec4bfc3c9f48ab1b363"},
            {427193, "a2f3c163a03066ff8bded2f38a0683b748c75bd286ad3381322574c9028d95f6"},
            {453537, "890eb3b2c0663f2199d3fa8606c4ccebadbf9872a7006c7217aa14cd90422ffa"},
            {462250, "87dfbb98eb3926634205c4d96176cec8c80d193dc4e629e75880bd09b5f995e3"},
            {468000, "6998c96de3c601762a86b9a8df334ebbb38e2e5abb87cc77145370c42f9d8afc"},
            {480200, "bd9060c1d9d84ccde25083d601768cfea34cc4b29be667a5a5bcddbb3d762748"},
            {484500, "f637a26cb08f4a195df2950ed2d1a24aeb8303886fdae6444636cb88933406a1"},
            {506000, "1dfabdeac35fec357600d2353e481ef593ba2535c46ee00afc83fc5afbff4ce6"},
            {544000, "df78a48378883d2402c2058806774a783179590b792b815fda47d523b70fc060"},
            {553300, "ad9ed2d8ddfa4281755881e98538287fb46e96cbd5969d58027097491f8be23f"},
            {580000, "6d2b6d733240a6ec5eb222cd924ccce295f61bd0c302edb8e92ca993b032c38d"},
            {602000, "70ada8e0ff346431b13f2948e9583df4e5f8967f5c8a54ec976fa2fcdfc70563"},
            {623000, "9a14b80669f6611516ea9199e480862195b2ae0c2121ac2bc3b831e3303fac1d"},
            {645000, "dabfbdfb5fa27172828ad1eadee9792bb042e2d702e612764760d48fc091e7f0"},
            {667000, "1a4e7863cde9996ab6615138fb97abe517f85bc32a98ded94e625192eabe9715"},
            {689000, "bc3aa82c961af1f58a9164d05c32e04a94bf8c9018facdf1f835753d43812562"},
            {713000, "e603ce44e95ced531d06570e45f7440e4e25d7b91ec2497b1ae2fa3631f55e94"},
            {750300, "e262941e29e18c19bef464ee7439ef90b95f84086ce49cc972746f9f6677856a"},
            {780000, "f62192ab4fae81212bd518f3d1803b0ce29974059934356c638f60788ab788bd"},
            {785500, "11fb235c9fcb9b40392b3ab2892ad6cc0de8fecc902b4144f03fb07584de7aca"},
            {789000, "68b18ab78aefc1cd621b99009a1b12489f2cd8afa443a50c68416ac1e50719b8"},
            {796000, "3449ef64a6765f1eb8bafbaab0846376e64e978c5f56e36223ce676b530c8e3f"},
            {800000, "a1ed05e9671acce3cfa7dd283f0be5320b8d626fe84be4703fc8d3be95ffcc59"},
            {804000, "43de8b3a0742bcaf22b028cd1d2a2b0e60b0f3ae47778d5f0565513d6405706d"},
            {810500, "370660575a42e1c14b9ffd336016a6ebf73ad3b6bf65a23c5c8efeb2218f1eb2"},
            {816000, "4a47e0e16e8db6f8a1a7d646530e9c6497fdc93b0bedfc06ab343390b72da2ed"},
            {822000, "91a7e00d77a8fdea84c5e92d08a2ed96d60a140aa4a595644e66f34ae4daf412"},
            {841000, "b6b8a1606ec43112ff2909f42c3a601a900b33d7cf61db7f4e987e2756edbf9b"},
            {890000, "05bcda7ed975d17bfb91d61736a785572e8853194b36855d5c46283f047d85bc"},
            {894000, "049a57925f060f2ddc47bc3a0c95e45267ef4f05a8c014c78b4f43b168d0651e"},
            {979000, "9eb900213cbe5e31824367da1d659bbffe7b7a540569387013136c002b4673ff"},
            {985548, "8195645708c336c83d402bf9e2ccbe7f1a840397cfed466b0a1286fa98cfd300"},
            {985549, "e2d3be0627ec23b01e0c9be5788ae99510ff8a138bc8555c8d3762833f35e37b"},
            {996000, "f1470ab1c1883e4930cb165ae87379c534b6cda818c0375a49397413c7152ed2"},
            {1021000, "9cdf145b064b03b35023de34e47096f3173177457ff48560636831c8ae9f3b0e"},
            {1039000, "cb4666e4d19d7724436c940fc7ea24d4ad298e11068b531b106fed637acbc67f"},
            {1170000, "59f2611e0f3458aa060197d9b40d9d43e450ca59cf46d637328c305af08e91e5"},
            {1268000, "16c1f28e8abc063884cf65fa577c9fdc58f7825c481e17f98bdb7db823124dbd"},
            {1272000, "4b4b163a4c1c20964690e01d975cfe5077b96433a4d840cdbc8743061a780296"},
            {1273000, "9fc4af795cb3a4cf89f5bac21768c03e8792c19bae350077b74981ef69b6a005"},
            {1278000, "0e5be0de34a3833dae3beb0cd466ce35ce0c68816c6f12b896a7db33d88beb89"},
            {1283000, "847cb630d498653301b761d341228393046954ef85ac28b53cb4960d5d6d8391"},
            {1324000, "edba75b01a7d69ea2c6aae7230b9007f2b842f1ec51645d7a2d62d1df0477e73"},
            {1329000, "2449f4efc35da48c512702866991d271acdc3be9a9780f22f1f4be96b7bad942"},
            {1343000, "612c5544806f33ec7ef96bcec400ed3119ac14f5b50a775a161bc6829c540131"},
            {1372000, "891c480f30c4a8484e41614d3fd7455901ee336f3f22d352a1e0e3d54849d5e9"}
};
} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
