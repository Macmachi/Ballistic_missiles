allTILKBallisticMissiles[]={"shahab3","iskander_9K720","minuteman_2","v2"};//add the missile class names here if new
allTILKLaunchPad[]={"v2_launchpad1","iskander_launchpad1"}; //add the launchpad class names here if new
class Land_CampingChair_V2_F;
class Wreck_base_F;

//config missiles
class MissilePropBase_F : Land_CampingChair_V2_F {
	author = "TILK";
	mapSize = 4;
	scope = 0;
	scopeCurator = 0;
	icon = "iconObject_1x2";
    editorCategory = "EdCat_missiles";
	destrType = "DestructBuilding";
	cost = 0;
	accuracy = 1000;
	class AttributeValues {
		objectIsSimple = 0;
	};
	// Strategic
	side = 3;
	armor = 250;  
	ladders[] = {};
	// Building
	//nameSound = "obj_building";
	// Static
	reversed = 0;
	hasDriver = 0;
	audible = 0;
	//simulation = "house";
	class DestructionEffects {};
	picture = "pictureStaticObject";
	weapons[] = {};
	magazines[] = {};
	irTarget = 0;
	type = 1;
	threat[] = {0, 0, 0};
	maxSpeed = 0;
	coefInside = 2;
	coefInsideHeur = 2;
	coefSpeedInside = 2;
	windSockExist = 0;
	countsForScoreboard = 0;
	class EventHandlers {
		init = "_this call TILK_fnc_ignition;";
		/*test*/
		killed = "_this call TILK_fnc_missileDestruction;"; 
		/* fin de test*/
		class CBA_Extended_EventHandlers {};
	};
	
};

//config launchers
class LauncherPropBase_F: Wreck_base_F {
	author = "TILK";
	mapSize = 4;
	
	class SimpleObject {
		eden = 0;
		animate[] = {};
		hide[] = {};
		verticalOffset = 0.829;
		verticalOffsetWorld = 0;
		init = "''";
	};
	scope = 0;
	scopeCurator = 0;
	icon = "iconObject_1x2";
	editorCategory = "EdCat_missiles";
	destrType = "DestructBuilding";
	cost = 0;
	accuracy = 1000;
	
	class AttributeValues {
		objectIsSimple = 0;
	};
	// Strategic
	side = 3;
	armor = 250;
	ladders[] = {};
	// Building
	//nameSound = "obj_building";
	// Static
	reversed = 0;
	hasDriver = 0;
	audible = 0;
	//simulation = "house";
	
	class DestructionEffects {};
	picture = "pictureStaticObject";
	weapons[] = {};
	magazines[] = {};
	irTarget = 0;
	type = 1;
	threat[] = {0, 0, 0};
	maxSpeed = 0;
	coefInside = 2;
	coefInsideHeur = 2;
	coefSpeedInside = 2;
	windSockExist = 0;
	countsForScoreboard = 0;
};


// MISSILES

class shahab3: MissilePropBase_F {

	editorPreview = "\Ballistic_missiles\media\icons\shahab3_icon.paa";
	scope = 2;
	scopeCurator = 2;
	displayName = "Shahab 3";
	model = "\Ballistic_missiles\objects\shahab3.p3d";
	icon = "iconObject_1x2";
    editorSubcategory = "EdSubcat_missiles_country_iran";

};

class iskander_9K720: MissilePropBase_F {
	
	editorPreview = "\Ballistic_missiles\media\icons\iskander_9K720_icon.paa";
	scope = 2;
	scopeCurator = 2;
	displayName = "Iskander 9K720 (SS-26 Stone)";
	model = "\Ballistic_missiles\objects\iskander_9K720.p3d";
	icon = "iconObject_1x2";
    editorSubcategory = "EdSubcat_missiles_country_russia";
	
};

class minuteman_2: MissilePropBase_F {
	
	editorPreview = "\Ballistic_missiles\media\icons\minuteman_2_icon.paa";
	scope = 2;
	scopeCurator = 2;
	displayName = "Minuteman II";
	model = "\Ballistic_missiles\objects\minuteman_2.p3d";
	icon = "iconObject_1x2";
    editorSubcategory = "EdSubcat_missiles_country_usa";
	

};

class v2: MissilePropBase_F {
	
	editorPreview = "\Ballistic_missiles\media\icons\v2_icon.paa";
	scope = 2; 
	scopeCurator = 2; 
	displayName = "V2";
	model = "\Ballistic_missiles\objects\v2.p3d";
	icon = "iconObject_1x2";
    editorSubcategory = "EdSubcat_missiles_country_germany";
	
	
};

// LAUNCHERS

class iskander_launchpad1: LauncherPropBase_F {
	
	editorPreview = "\Ballistic_missiles\media\icons\iskander_launchpad1_icon.paa";
	scope = 1; // Désactiver car fonction d'attachement pas fonctionnelle !
	scopeCurator = 1; // Désactiver car fonction d'attachement pas fonctionnelle !
	displayName = "Iskander launchpad 1";
	model = "\Ballistic_missiles\objects\iskander_launchpad1.p3d";
	icon = "iconObject_1x2";
    editorSubcategory = "EdSubcat_missiles_country_russia";
	class EventHandlers {
		/*Test - Non fonctionel, donne un message d'erreur avec ";" missing */
        //init = "[this, 'iskander_9K720'] call TILK_fnc_launchpadAttach.sqf;";
		/* fin du test*/
		class CBA_Extended_EventHandlers {};
	};
};	

class v2_launchpad1: LauncherPropBase_F {
	
	editorPreview = "\Ballistic_missiles\media\icons\v2_launchpad1_icon.paa";
	scope = 1; // Désactiver car fonction d'attachement pas fonctionnelle !
	scopeCurator = 1; // Désactiver car fonction d'attachement pas fonctionnelle !
	displayName = "V2 launchpad 1";
	model = "\Ballistic_missiles\objects\v2_launchpad1.p3d";
	icon = "iconObject_1x2";
    editorSubcategory = "EdSubcat_missiles_country_germany";
	class EventHandlers {
		/*Test - Non fonctionel, donne un message d'erreur avec ";" missing */
        //init = "[this, 'v2'] call TILK_fnc_launchpadAttach.sqf;";
		/* fin du test*/
		class CBA_Extended_EventHandlers {};
	};	
};