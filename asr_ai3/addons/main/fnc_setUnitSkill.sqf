// sets random skill depending on unit's class
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
private["_t","_sc","_sa","_i","_st","_sv","_fc","_fnc_getskillvalue"];
PARAMS_1(_unit);

_fnc_getskillvalue = {
	private["_sv","_min","_var"];
	_min = _this select 0; //min skill
	_var = _this select 1; //max variance
	//_sv = if (random 50 < 1) then {_min + _var} else {_min + random _var};
	//_sv
	(_min + random _var)
};

_t = typeOf _unit;
_sc = [configfile>>"cfgvehicles">>_t>>"asr_ai_level", "number", 6] call CBA_fnc_getConfigEntry;
TRACE_2("config",_unit,_sc);

// also check for override setting
_i = 0;
{
	if (_t in _x) exitWith {
		_sc = _i;
		TRACE_2("override",_unit,_i);
	};
	INC(_i);
}
forEach GVAR(levels_units);

_sa = GVAR(sets) select _sc; // get skill array for this unit
if (count _sa == 0) exitWith {}; // do not run if empty
if (isNull _unit) exitWith {};

_fc = 1;
if (count GVAR(factions) > 0) then {
	{ if (faction _unit == _x select 0) exitWith {_fc = _x select 1} } forEach GVAR(factions); TRACE_2("Faction coefficient",_unit,_fc);
};

_i = 0;
while {_i < count _sa} do {
	_st = _sa select _i; // skill type
	INC(_i);
	switch (_st) do {
		case "general": {
			{
				_sv = ((_sa select _i) call _fnc_getskillvalue) * _fc;
				[[_unit,[_x,_sv]], QUOTE(FUNC(setSkill)), _unit, false, true] call BIS_fnc_MP;
			}
			forEach ["general","courage","reloadSpeed","commanding"];
		};
		case "aiming": {
			{
				_sv = ((_sa select _i) call _fnc_getskillvalue) * _fc;
				[[_unit,[_x,_sv]], QUOTE(FUNC(setSkill)), _unit, false, true] call BIS_fnc_MP;
			}
			forEach ["aimingAccuracy","aimingShake","aimingSpeed"];
		};
		case "spotting": {
			{
				_sv = ((_sa select _i) call _fnc_getskillvalue) * _fc;
				[[_unit,[_x,_sv]], QUOTE(FUNC(setSkill)), _unit, false, true] call BIS_fnc_MP;
			}
			forEach ["spotDistance","spotTime"];
		};
	};
	INC(_i);
};

sleep 5;
_unit setVariable [QGVAR(configured),true];
