/*
* generates particles and animates the missile (is mp compatible)
*/

0 = _this spawn {

	_missile = _this select 0;

	waitUntil {_missile getVariable ["TILK_MissileLaunch",false];};
	
	[_missile] call TILK_fnc_setMissileDamages;
	
	sleep 0.2;	// We wait to check if the missile is destroyed before play sound or create light
	
	//add the position of the object's mem (reactor) in a variable
	_emiterpos= _missile modelToWorld (_missile selectionPosition "reactor"); 

	//simulates emissive flame color (during the night)
	_lightBooster = "#lightpoint" createVehicleLocal _emiterpos; 
	_lightBooster setLightBrightness 2; 
	_lightBooster setLightAmbient [2.55, 1.02, 0.51]; 
	_lightBooster setLightColor [2.55, 1.02, 0.51]; 
	_lightBooster attachTo [_missile, [0, 0, 0], "reactor"];
	
	if (!alive _missile) exitWith 
		{
		    sleep 3;
			deleteVehicle _lightBooster;
	    };
	
	//play the sound during takeoff if missile is alive!
	playSound3D ["ballistic_missiles\media\sounds\missilelaunchsound.ogg", _missile, false, getPosASL _missile, 5, 1, 3000]; //can be heard up to 3kms 
	
	//smoke particle (1) on ignition of thrusters
	_PS1 = "#particlesource" createVehicleLocal _emiterpos;
	_PS1 setParticleCircle [0, [0, 0, 0]];
	_PS1 setParticleRandom [0, [10, 10, 2], [0.5, 0.5, 0], 0, 0.25, [0.05, 0.05, 0.05, 0.05], 0, 0];
	_PS1 setParticleParams [
		["\A3\data_f\ParticleEffects\Universal\smoke.p3d", 8, 3, 1],
		"", 
		"Spaceobject",
		1,
		25,
		"Reactor",
		[0,0,0],
		0.2,
		3,
		2,
		1,
		[6,6,6,0], 
		[[4, 5, 10, 10]],
		[1,0.5],
		1,
		0,
		"",
		"",
		_missile,
		0,
		true,
		1,
		[[0.1, 0.1, 0.1, 0.75]]			
	];

	_PS1 setDropInterval 0.002;

	sleep 2; //break 

	//smoke particle (2) 
	_PS2 = "#particlesource" createVehicleLocal _emiterpos;
	_PS2 setParticleCircle [0, [0, 0, 0]];
	_PS2 setParticleRandom [0, [0, 0, 0], [0.5, 0.5, 0], 0, 0.25, [0.05, 0.05, 0.05, 0.05], 0, 0];
	_PS2 setParticleParams [
		["\A3\data_f\ParticleEffects\Universal\smoke.p3d", 8, 3, 1],
		"", 
		"Spaceobject",
		1,
		18,
		"Reactor",
		[0,0,0],
		0.2,
		3,
		2,
		1,
		[2,2,2,0], 
		[[4, 5, 10, 10]],
		[1,0.5],
		0,
		0,
		"",
		"",
		_missile,
		0,
		true,
		1,
		[[0.1, 0.1, 0.1, 0.75]]
	];
		
	_PS2 setDropInterval 0.002;

	//fire particle (1)
	_PS3 = "#particlesource" createVehicleLocal _emiterpos;
	_PS3 setParticleCircle [0, [0, 0, 0]];
	_PS3 setParticleRandom [0, [0, 0, 0], [0.5, 0.5, 0.5], 0, 0.25, [0.05, 0.05, 0.05, 0.05], 0, 0];
	_PS3 setParticleParams [
		["\A3\data_f\ParticleEffects\Universal\Universal.p3d",16,10,32], 
		"",
		"billboard",
		1,
		0.8,
		"Reactor",
		[0, 0, 0],
		1,
		0.0565,
		0.045,
		0.025,
		[1.5,1.5,1.5,0], 
		[[4, 5, 10, 10]],
		[1,0],
		0,
		0,
		"",
		"",
		_missile,
		90,
		false,
		0,
		[[1,1,1,-0],[1,1,1,-1],[1,1,1,-1],[1,1,1,-1],[1,1,1,-1],[1,1,1,-0]]
					
	];

	_PS3 setDropInterval 0.02;
			
	//fire particle (2)
	_PS4 = "#particlesource" createVehicleLocal _emiterpos;
	_PS4 setParticleCircle [0, [0, 0, 0]];
	_PS4 setParticleRandom [0, [0, 0, 0], [0.5, 0.5, 0.5], 0, 0.25, [0.05, 0.05, 0.05, 0.05], 0, 0];
	_PS4 setParticleParams [
		["\A3\data_f\ParticleEffects\Universal\Universal.p3d",16,10,32], 
		"",
		"billboard",
		1,
		0.5,
		"Reactor",
		[0, 0, 0],
		1,
		0.0565,
		0.045,
		0.025,
		[4,4,4,0], 
		[[4, 5, 10, 10]],
		[1,0],
		0,
		0,
		"",
		"",
		_missile,
		90,
		false,
		0,
		[[1,1,1,-0],[1,1,1,-1],[1,1,1,-1],[1,1,1,-1],[1,1,1,-1],[1,1,1,-0]]
	];

	sleep 1; //break 
		
	deleteVehicle _PS1; //delete smoked particle (number 1) on ignition of thrusters
	_PS4 setDropInterval 0.02;

	//animation starts here
	//the following scope is executed in parallel
	_missile setVelocity [0,0,10];
	[_missile,_lightbooster] spawn {
		params ["_missile","_lightBooster"];
		
		//exponential increase of the velocity of the missile during 200 iterations
		_startVelocity = 1;
		
		for "_i" from 1 to 200 do 
			{
				_missile setVelocity [(vectorUp _missile select 0)*_i,(vectorUp _missile select 1) *_i,(vectorUp _missile select 2)*_i];
				sleep 0.1; //break
				/* COMMENTER car les launchers ne sont pas encore debug mais a tester ensuite sur dédié
				//check if the missile is touching the ground, if yes, we detach him
				if ((isTouchingGround _missile) && (_i == 10)) then
				{		
					detach _missile;
					_missile setPos (_missile modelToWorld [0,0,4]);	
				}; 
				*/ // A DECOMMENTER JUSQU'ICI
				//hint format ["Loop %1 vel %2",str _i, str velocity _missile]; //debug
				
			};
		
		sleep 39; //break
		deleteVehicle _lightBooster;
		deleteVehicle _missile;
	};

	
	//the following scope is executed in parallel and destroyed PS4 when the missile reaches 100m
	[_PS4] spawn {
		params ["_PS4"];
		sleep 6; //break
		deleteVehicle _PS4;
	};
	
};