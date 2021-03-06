class CfgPatches {
    class Missiles {
        units[] = {
		"shahab3",
		"iskander_9K720",
		"minuteman_2",
		"iskander_launchpad1",
		"v2",
		"v2_launchpad1"
        }; 
        weapons[] = {}; 
        requiredVersion = 1; 
        requiredAddons[] = {}; 
    };
};

#include "\Ballistic_missiles\InterfaceHpps\defines.hpp"
#include "\Ballistic_missiles\InterfaceHpps\interface.hpp"

class cfgFunctions
{
	#include "\Ballistic_missiles\Functions\functions.hpp"
};

class cfgVehicles
{
	#include"\Ballistic_missiles\Hpps\missiles.hpp"
};

class CfgEditorCategories
{
	class EdCat_missiles // Category class, you point to it in editorCategory property
	{
		displayName = "Ballistic missiles"; // Name visible in the list
	};
};

class CfgEditorSubcategories
{
	class EdSubcat_missiles_country_iran // Category class, you point to it in editorSubcategory property
	{
		displayName = "Iran"; // Name visible in the list
	};
	class EdSubcat_missiles_country_russia // Category class, you point to it in editorSubcategory property
	{
		displayName = "Russia"; // Name visible in the list
	};	
	class EdSubcat_missiles_country_usa // Category class, you point to it in editorSubcategory property
	{
		displayName = "USA"; // Name visible in the list
	};	
	class EdSubcat_missiles_country_germany // Category class, you point to it in editorSubcategory property
	{
		displayName = "Germany"; // Name visible in the list
	};		
};