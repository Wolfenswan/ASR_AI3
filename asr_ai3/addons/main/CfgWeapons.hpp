class Mode_SemiAuto {
	ASR_AI_ROF_RIFLE_SMALL_SEMI;
	ASR_AI_DISP_REGULAR;
};
class Mode_Burst: Mode_SemiAuto {
	ASR_AI_ROF_RIFLE_SMALL_CLOSE_BURST;
	ASR_AI_DISP_REGULAR;
};
class Mode_FullAuto: Mode_SemiAuto {
	ASR_AI_ROF_RIFLE_SMALL_FULLAUTO;
	ASR_AI_DISP_REGULAR;
};

class CfgWeapons {

	class Default {
		ASR_AI_ROF_RIFLE_SMALL_SEMI;
		ASR_AI_DISP_REGULAR;
	};
	class PistolCore: Default {
		ASR_AI_DISP_REGULAR;
	};
	class RifleCore: Default {
		ASR_AI_DISP_REGULAR;
	};
	class MGunCore: Default {
		ASR_AI_DISP_REGULAR;
	};
	class LauncherCore: Default {
		ASR_AI_DISP_REGULAR;
	};
	class GrenadeCore: Default {
		ASR_AI_DISP_REGULAR;
	};
	class CannonCore: Default {
		ASR_AI_DISP_REGULAR;
	};

	class MGun: MGunCore {
		ASR_AI_DISP_REGULAR;
		asr_ai_wtype = ASR_WEAPON_TYPE_MG;
	};
	class Launcher: LauncherCore {
		ASR_AI_DISP_REGULAR;
		asr_ai_wtype = ASR_WEAPON_TYPE_LAUNCHER;
	};
	class GrenadeLauncher: Default {
		ASR_AI_ROF_GL_SINGLE;
		ASR_AI_DISP_REGULAR;
	};
	class Rifle: RifleCore {
		ASR_AI_DISP_REGULAR;
		asr_ai_wtype = ASR_WEAPON_TYPE_RIFLE;
	};
	class HandGunBase: Rifle {
		ASR_AI_ROF_PISTOL_SEMI;
		asr_ai_wtype = ASR_WEAPON_TYPE_PISTOL;
	};
	class Pistol: PistolCore {
		ASR_AI_DISP_REGULAR;
		asr_ai_wtype = ASR_WEAPON_TYPE_PISTOL;
	};
	class Pistol_Base_F: Pistol {
		ASR_AI_ROF_PISTOL_SEMI;
	};
	class Throw: GrenadeLauncher {
		class ThrowMuzzle: GrenadeLauncher {
			ASR_AI_DISP_REGULAR;
		};
		class HandGrenadeMuzzle: ThrowMuzzle {
			minRange = 20;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.9;
		};
		class MiniGrenadeMuzzle: ThrowMuzzle {
			minRange = 15;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.9;
		};
	};

	class Rifle_Base_F: Rifle {};
	class Rifle_Long_Base_F: Rifle_Base_F {};
	class UGL_F;

	class EBR_base_F: Rifle_Long_Base_F {
 		modes[] = {"Single", "FullAuto", "ASR_AI_Burst_close", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2"};
 		ASR_AI_RIFLE_MEDIUM_MODES(Mode_SemiAuto,Mode_FullAuto);
		ASR_AI_DISP_REGULAR;
	};

	class DMR_01_base_F: Rifle_Long_Base_F {
 		modes[] = {"Single", "FullAuto", "ASR_AI_Burst_close", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2"};
 		ASR_AI_RIFLE_MEDIUM_MODES(Mode_SemiAuto,Mode_FullAuto);
		ASR_AI_DISP_REGULAR;
	};

	class LMG_Mk200_F: Rifle_Long_Base_F {
		modes[] = {"manual", "ASR_AI_Burst_close", "ASR_AI_Burst_short", "ASR_AI_Burst_medium", "ASR_AI_Burst_far", "ASR_AI_Burst_far_optic1", "ASR_AI_Burst_far_optic2"};
		ASR_AI_MG_MODES(manual,Mode_FullAuto,manual);
		ASR_AI_DISP_REGULAR;
		asr_ai_wtype = ASR_WEAPON_TYPE_AR;
		asr_ai_hasbipod = 1;
	};

	class arifle_Katiba_Base_F: Rifle_Base_F {
		modes[] = {"Single", "FullAuto", "ASR_AI_Burst_close", "ASR_AI_Burst_far", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2"};
		ASR_AI_RIFLE_SMALL_MODES(Mode_SemiAuto,Mode_FullAuto);
		ASR_AI_DISP_REGULAR;
		class EGLM: UGL_F {};
	};
	class arifle_Katiba_C_F: arifle_Katiba_Base_F {
		modes[] = {"Single", "FullAuto", "ASR_AI_Burst_close", "ASR_AI_Burst_far", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2"};
		ASR_AI_RIFLE_SMALL_CQB_MODES(Single,FullAuto);
		ASR_AI_DISP_REGULAR;
	};

	class arifle_MX_Base_F: Rifle_Base_F {
		modes[] = {"Single", "FullAuto", "ASR_AI_Burst_close", "ASR_AI_Burst_close2", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2"};
		ASR_AI_RIFLE_SMALL_MODES(Mode_SemiAuto,Mode_FullAuto);
		ASR_AI_DISP_REGULAR;
	};
	class arifle_MXC_F: arifle_MX_Base_F {
		modes[] = {"Single", "FullAuto", "ASR_AI_Burst_close", "ASR_AI_Burst_close2", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2"};
		ASR_AI_RIFLE_SMALL_CQB_MODES(Single,FullAuto);
		ASR_AI_DISP_REGULAR;
	};
	class arifle_MX_SW_F: arifle_MX_Base_F {
		modes[] = {"Single","manual", "ASR_AI_Burst_close", "ASR_AI_Burst_short", "ASR_AI_Burst_medium", "ASR_AI_Burst_far", "ASR_AI_Burst_far_optic1", "ASR_AI_Burst_far_optic2"};
		ASR_AI_MG_MODES(manual,FullAuto,Mode_SemiAuto);
		ASR_AI_DISP_REGULAR;
		asr_ai_wtype = ASR_WEAPON_TYPE_AR;
		asr_ai_hasbipod = 1;
	};
	class arifle_MXM_F: arifle_MX_Base_F {
		modes[] = {"Single", "FullAuto", "ASR_AI_Burst_close", "ASR_AI_Burst_close2", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2"};
		ASR_AI_RIFLE_SMALL_MODES(Single,FullAuto);
	};

	class SDAR_base_F: Rifle_Base_F {
		modes[] = {"Single", "Burst", "FullAuto"};
		ASR_AI_SMG_MODES;
		ASR_AI_DISP_REGULAR;
	};

	class Tavor_base_F: Rifle_Base_F {
		modes[] = {"Single", "FullAuto", "ASR_AI_Burst_close", "ASR_AI_Burst_far", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2"};
		ASR_AI_RIFLE_SMALL_CQB_MODES(Mode_SemiAuto,Mode_FullAuto);
		ASR_AI_DISP_REGULAR;
	};
	class arifle_TRG21_F: Tavor_base_F {
		modes[] = {"Single", "FullAuto", "ASR_AI_Burst_close", "ASR_AI_Burst_far", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2"};
		ASR_AI_RIFLE_SMALL_MODES(Single,FullAuto);
	};

	class LMG_Zafir_F: Rifle_Long_Base_F {
		modes[] = {"FullAuto", "Single", "ASR_AI_Burst_close", "ASR_AI_Burst_short", "ASR_AI_Burst_medium", "ASR_AI_Burst_far", "ASR_AI_Burst_far_optic1", "ASR_AI_Burst_far_optic2"};
		ASR_AI_MG_MODES(FullAuto,Mode_FullAuto,Mode_SemiAuto);
		ASR_AI_DISP_REGULAR;
		asr_ai_wtype = ASR_WEAPON_TYPE_MG;
		asr_ai_hasbipod = 1;
	};

	class mk20_base_F: Rifle_Base_F {
		modes[] = {"Single", "FullAuto", "ASR_AI_Burst_close", "ASR_AI_Burst_far", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2"};
		ASR_AI_RIFLE_SMALL_MODES(Mode_SemiAuto,Mode_FullAuto);
		ASR_AI_DISP_REGULAR;
	};
	class arifle_Mk20C_F: mk20_base_F {
		modes[] = {"Single", "FullAuto", "ASR_AI_Burst_close", "ASR_AI_Burst_far", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2"};
		ASR_AI_RIFLE_SMALL_CQB_MODES(Single,FullAuto);
	};

	class SMG_01_Base: Rifle_Base_F {
		modes[] = {"Single", "Burst", "FullAuto"};
		class Single: Mode_SemiAuto {
			ASR_AI_ROF_SMG_SINGLE;
		};
		class Burst: Mode_Burst {
			burst = 2;
			ASR_AI_ROF_SMG_BURST;
		};
		class FullAuto: Mode_FullAuto {
			ASR_AI_ROF_SMG_FULLAUTO;
		};
		ASR_AI_DISP_REGULAR;
	};

	class SMG_02_base_F: Rifle_Base_F {
		modes[] = {"Single", "Burst", "FullAuto"};
		ASR_AI_SMG_MODES;
		ASR_AI_DISP_REGULAR;
	};

	class pdw2000_base_F: Rifle_Base_F {
		modes[] = {"Single", "Burst", "FullAuto"};
		class Single: Mode_SemiAuto {
			ASR_AI_ROF_SMG_SINGLE;
		};
		class Burst: Mode_Burst {
			showToPlayer = 0;
			burst = 2 + round random 3;
			ASR_AI_ROF_SMG_BURST;
		};
		class FullAuto: Mode_FullAuto {
			ASR_AI_ROF_SMG_FULLAUTO;
		};
		ASR_AI_DISP_REGULAR;
	};

	class GM6_base_F: Rifle_Long_Base_F {
		modes[] = {"Single", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2", "ASR_AI_Single_far_optics2"};
		ASR_AI_BIGSNIPER_MODES(Mode_SemiAuto);
		asr_ai_wtype = ASR_WEAPON_TYPE_SNIPER;
		asr_ai_hasbipod = 1;
	};

	class LRR_base_F: Rifle_Long_Base_F {
		modes[] = {"Single", "ASR_AI_Single_optics1", "ASR_AI_Single_optics2", "ASR_AI_Single_far_optics2"};
		ASR_AI_BIGSNIPER_MODES(Mode_SemiAuto);
		asr_ai_wtype = ASR_WEAPON_TYPE_SNIPER;
		asr_ai_hasbipod = 1;
	};

	class LMG_RCWS: MGun {
		ASR_AI_DISP_SNIPER;
	};
	class M134_minigun: MGunCore {
		class LowROF: Mode_FullAuto {
			ASR_AI_DISP_REGULAR;
		};
	};
	class autocannon_Base_F: CannonCore {
		class player;
		class close: player {
			ASR_AI_DISP_SNIPER;
		};
	};
	class gatling_30mm: CannonCore {
		class LowROF: Mode_FullAuto {
			ASR_AI_DISP_SNIPER;
		};
	};
	class cannon_120mm: CannonCore {
		class player;
		class close: player {
			ASR_AI_DISP_SNIPER;
		};
	};

	class Gatling_30mm_Plane_CAS_01_F: CannonCore {
		class LowROF: Mode_FullAuto {
			ASR_AI_DISP_SNIPER;
		};
	};
	class Cannon_30mm_Plane_CAS_02_F: CannonCore {
		class LowROF: Mode_FullAuto {
			ASR_AI_DISP_SNIPER;
		};
	};
	class cannon_105mm: cannon_120mm {
		class player;
		class close: player {
			ASR_AI_DISP_SNIPER;
		};
	};

	class ItemCore;
	class InventoryOpticsItem_Base_F;

	class optic_NVS : ItemCore {
		class ItemInfo : InventoryOpticsItem_Base_F {
			opticType = 1;
		};
	};
	class optic_tws : ItemCore {
		class ItemInfo : InventoryOpticsItem_Base_F {
			opticType = 1;
		};
	};
	class optic_tws_mg : ItemCore {
		class ItemInfo : InventoryOpticsItem_Base_F {
			opticType = 1;
		};
	};

	class optic_Arco : ItemCore {
		class ItemInfo;
		asr_ai_variants[] = {"optic_Arco","ASR_optic_Arco_AI_N"};
	};
	class ASR_optic_Arco_AI_N : optic_Arco {
		scope = 1;
		class ItemInfo : ItemInfo {
			opticType = 0;
		};
	};
	
	class optic_Hamr : ItemCore {
		class ItemInfo;
		asr_ai_variants[] = {"optic_Hamr","ASR_optic_Hamr_AI_N"};
	};
	class ASR_optic_Hamr_AI_N : optic_Hamr {
		scope = 1;
		class ItemInfo : ItemInfo {
			opticType = 0;
		};
	};
	
	class optic_SOS : ItemCore {
		class ItemInfo;
		asr_ai_variants[] = {"optic_SOS","ASR_optic_SOS_AI_N"};
	};
	class ASR_optic_SOS_AI_N : optic_SOS {
		scope = 1;
		class ItemInfo : ItemInfo {
			opticType = 0;
		};
	};
	
	class optic_MRCO : ItemCore {
		class ItemInfo;
		asr_ai_variants[] = {"optic_MRCO","ASR_optic_MRCO_AI_N"};
	};
	class ASR_optic_MRCO_AI_N : optic_MRCO {
		scope = 1;
		class ItemInfo : ItemInfo {
			opticType = 0;
		};
	};
	
	class optic_DMS : ItemCore {
		class ItemInfo;
		asr_ai_variants[] = {"optic_DMS","ASR_optic_DMS_AI_N"};
	};
	class ASR_optic_DMS_AI_N : optic_DMS {
		scope = 1;
		class ItemInfo : ItemInfo {
			opticType = 0;
		};
	};
	
	class optic_LRPS : ItemCore {
		class ItemInfo;
		asr_ai_variants[] = {"optic_LRPS","ASR_optic_LRPS_AI_N"};
	};
	class ASR_optic_LRPS_AI_N : optic_LRPS {
		scope = 1;
		class ItemInfo : ItemInfo {
			opticType = 0;
		};
	};

};
