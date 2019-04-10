#include "StrucTigerLUT.h"

void StrucTigerLUT::init()
{
	SLUT_SET_FILE(":/StrucTiger.h");

	SLUT_INSERT_FK("rnti");
	SLUT_INSERT_FK("ueid");
	SLUT_INSERT_FK("traceKey");
	SLUT_INSERT_FK("traceid");
	SLUT_INSERT_FK("pci");
	SLUT_INSERT_FK("uldlid");

	////////ver = 0
	SLUT_SET_TYPE(0);
	SLUT_SET_VER(0);
	
	SLUT_ADD_SP(TT_ID_0x507);
	SLUT_SET_RANKS_4_SP("TT507_v0_t", "UL SRS measurement", "UL Measurement", "LTE");	
	SLUT_SET_FC_4_SP(1);
	SLUT_ADD_FP_4_SP("ueid", SHOW_MASK_NORMAL, "");
	SLUT_ADD_FP_4_SP("sync_state", SHOW_MASK_NORMAL, "");
	SLUT_ADD_FP_4_SP("fdfs", SHOW_MASK_KV, "");
	SLUT_ADD_KV_4_FP("0", "fds");
	SLUT_ADD_KV_4_FP("1", "fss");
	SLUT_ADD_FP_4_SP("sfn", SHOW_MASK_NORMAL, "");
	SLUT_ADD_FP_4_SP("subframe", SHOW_MASK_NORMAL, "");
	SLUT_ADD_FP_4_SP("se_corr", SHOW_MASK_NORMAL, "");
	SLUT_ADD_FP_4_SP("average_wb_sinr_srs_db", SHOW_MASK_NORMAL, "");
	SLUT_ADD_FP_4_SP("wb_combined_srs_db_from_dsp", SHOW_MASK_NORMAL, "");


	SLUT_ADD_SP(TT_ID_0x917);
	SLUT_SET_RANKS_4_SP("TT917_v0_t", "UL PUC", "UL Measurement", "LTE");
	SLUT_ADD_SP(TT_ID_0x80A);
	SLUT_SET_RANKS_4_SP("TT80a_v0_t", "DL AN", "UL Measurement", "LTE");
	SLUT_ADD_SP(TT_ID_0x801);
	SLUT_SET_RANKS_4_SP("TT801_v0_t", "DL SCH", "Scheduling", "LTE");

	////////ver = 1
	SLUT_SET_TYPE(0);
	SLUT_SET_VER(1);
	SLUT_ADD_SP(TT_ID_0x507);
	SLUT_SET_RANKS_4_SP("TT507_v0_t", "UL SRS measurement", "UL Measurement", "LTE");

	SLUT_SET_FILTER_PREFIX("tiger.");
	SLUT_SET_FILTER_KEY("tiger.traceid");
	SLUT_GEN_CATLUT();
}