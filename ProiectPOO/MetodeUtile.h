#pragma once

class MetodeUtile {
public:
	static bool contineDoarLitere(string);

	static bool contineDoarCifre(string);
	
	static bool valideazaData(string);

	static bool valideazaOra(string);

	static bool valideazaTipFisier(string);

	static bool verificareDataEsteInViitor(string);

	static bool verificarePrimaDataEsteInainte(string, string);

	static bool verificarePrimaOraEsteInainte(string, string);

	static string toLowerCase(string);
};