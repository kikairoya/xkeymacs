// DotXkeymacs.h: interface for the CDotXkeymacs class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOTXKEYMACS_H__0538C427_5733_47DA_B2C6_2E957EEFC59D__INCLUDED_)
#define AFX_DOTXKEYMACS_H__0538C427_5733_47DA_B2C6_2E957EEFC59D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct Language
{
	WORD wLanguage;
	LPCTSTR szLanguage;
} Language_t;

static const Language_t Languages[] = {
	{ 0x0001, _T("Arabic") },
	{ 0x0004, _T("Chinese") },
	{ 0x0009, _T("English") },
	{ 0x0401, _T("Arabic (Saudi Arabia)") },
	{ 0x0402, _T("Bulgarian") },
	{ 0x0403, _T("Catalan") },
	{ 0x0404, _T("Chinese (Taiwan)") },
	{ 0x0405, _T("Czech") },
	{ 0x0406, _T("Danish") },
	{ 0x0407, _T("German (Germany)") },
	{ 0x0408, _T("Greek") },
	{ 0x0409, _T("English (United States)") },
	{ 0x040A, _T("Spanish (Traditional Sort)") },
	{ 0x040B, _T("Finnish") },
	{ 0x040C, _T("French (France)") },
	{ 0x040D, _T("Hebrew") },
	{ 0x040E, _T("Hungarian") },
	{ 0x040F, _T("Icelandic") },
	{ 0x0410, _T("Italian (Italy)") },
	{ 0x0411, _T("Japanese") },
	{ 0x0412, _T("Korean") },
	{ 0x0413, _T("Dutch (Netherlands)") },
	{ 0x0414, _T("Norwegian (Bokmal)") },
	{ 0x0415, _T("Polish") },
	{ 0x0416, _T("Portuguese (Brazil)") },
	{ 0x0417, _T("Rhaeto-Romanic") },
	{ 0x0418, _T("Romanian") },
	{ 0x0419, _T("Russian") },
	{ 0x041A, _T("Croatian") },
	{ 0x041B, _T("Slovak") },
	{ 0x041C, _T("Albanian") },
	{ 0x041D, _T("Swedish") },
	{ 0x041E, _T("Thai") },
	{ 0x041F, _T("Turkish") },
	{ 0x0420, _T("Urdu") },
	{ 0x0421, _T("Indonesian") },
	{ 0x0422, _T("Ukrainian") },
	{ 0x0423, _T("Belarusian") },
	{ 0x0424, _T("Slovenian") },
	{ 0x0425, _T("Estonian") },
	{ 0x0426, _T("Latvian") },
	{ 0x0427, _T("Lithuanian") },
	{ 0x0428, _T("Tajik") },
	{ 0x0429, _T("Farsi") },
	{ 0x042A, _T("Vietnamese") },
	{ 0x042B, _T("Armenian") },
	{ 0x042C, _T("Azeri (Latin)") },
	{ 0x042D, _T("Basque") },
	{ 0x042E, _T("Sorbian") },
	{ 0x042F, _T("Macedonian (FYROM)") },
	{ 0x0430, _T("Sutu") },
	{ 0x0431, _T("Tsonga") },
	{ 0x0432, _T("Tswana") },
	{ 0x0434, _T("Xhosa") },
	{ 0x0435, _T("Zulu") },
	{ 0x0436, _T("Afrikaans") },
	{ 0x0437, _T("Georgian") },
	{ 0x0438, _T("Faeroese") },
	{ 0x0439, _T("Hindi") },
	{ 0x043A, _T("Maltese") },
	{ 0x043C, _T("Gaelic") },
	{ 0x043D, _T("Yiddish") },
	{ 0x043E, _T("Malay (Malaysia)") },
	{ 0x043F, _T("Kazakh") },
	{ 0x0440, _T("Kyrgyz") },
	{ 0x0441, _T("Swahili") },
	{ 0x0442, _T("Turkmen") },
	{ 0x0443, _T("Uzbek (Latin)") },
	{ 0x0444, _T("Tatar") },
	{ 0x0445, _T("Bengali") },
	{ 0x0446, _T("Punjabi") },
	{ 0x0447, _T("Gujarati") },
	{ 0x0448, _T("Oriya") },
	{ 0x0449, _T("Tamil") },
	{ 0x044A, _T("Telugu") },
	{ 0x044B, _T("Kannada") },
	{ 0x044C, _T("Malayalam") },
	{ 0x044D, _T("Assamese") },
	{ 0x044E, _T("Marathi") },
	{ 0x044F, _T("Sanskrit") },
	{ 0x0450, _T("Mongolian") },
	{ 0x0456, _T("Galician") },
	{ 0x0457, _T("Konkani") },
	{ 0x0458, _T("Manipuri") },
	{ 0x0459, _T("Sindhi") },
	{ 0x045A, _T("Syriac") },
	{ 0x045B, _T("Sinhalese") },
	{ 0x045C, _T("Cherokee") },
	{ 0x045D, _T("Inuktitut") },
	{ 0x045E, _T("Amharic") },
	{ 0x045F, _T("Tamazight (Berber/Arabic)") },
	{ 0x0460, _T("Kashmiri (Arabic)") },
	{ 0x0461, _T("Nepali") },
	{ 0x0462, _T("Frisian") },
	{ 0x0463, _T("Pashto") },
	{ 0x0464, _T("Filipino") },
	{ 0x0465, _T("Dhivehi") },
	{ 0x0466, _T("Edo") },
	{ 0x0467, _T("Fulfulde") },
	{ 0x0468, _T("Hausa") },
	{ 0x0469, _T("Ibibio") },
	{ 0x046A, _T("Yoruba") },
	{ 0x0470, _T("Igbo") },
	{ 0x0471, _T("Kanuri") },
	{ 0x0472, _T("Oromo") },
	{ 0x0473, _T("Tigrigna (Ethiopia)") },
	{ 0x0475, _T("Hawaiian") },
	{ 0x0476, _T("Latin") },
	{ 0x0477, _T("Somali") },
	{ 0x0478, _T("Yi") },
	{ 0x0801, _T("Arabic (Iraq)") },
	{ 0x0804, _T("Chinese (PRC)") },
	{ 0x0807, _T("German (Switzerland)") },
	{ 0x0809, _T("English (United Kingdom)") },
	{ 0x080A, _T("Spanish (Mexico)") },
	{ 0x080C, _T("French (Belgium)") },
	{ 0x0810, _T("Italian (Switzerland)") },
	{ 0x0813, _T("Dutch (Belgium)") },
	{ 0x0814, _T("Norwegian (Nynorsk)") },
	{ 0x0816, _T("Portuguese (Portugal)") },
	{ 0x0818, _T("Romanian (Moldova)") },
	{ 0x0819, _T("Russian (Moldova)") },
	{ 0x081A, _T("Serbian (Latin)") },
	{ 0x081D, _T("Swedish (Finland)") },
	{ 0x082C, _T("Azeri (Cyrillic)") },
	{ 0x0843, _T("Uzbek (Cyrillic)") },
	{ 0x085F, _T("Tamazight (Latin)") },
	{ 0x0873, _T("Tigrigna (Eritrea)") },
	{ 0x0C01, _T("Arabic (Egypt)") },
	{ 0x0C04, _T("Chinese (Hong Kong SAR)") },
	{ 0x0C07, _T("German (Austria)") },
	{ 0x0C09, _T("English (Australia)") },
	{ 0x0C0A, _T("Spanish (International Sort)") },
	{ 0x0C0C, _T("French (Canada)") },
	{ 0x0C1A, _T("Serbian (Cyrillic)") },
	{ 0x1001, _T("Arabic (Libya)") },
	{ 0x1004, _T("Chinese (Singapore)") },
	{ 0x1007, _T("German (Luxembourg)") },
	{ 0x1009, _T("English (Canada)") },
	{ 0x100A, _T("Spanish (Guatemala)") },
	{ 0x100C, _T("French (Switzerland)") },
	{ 0x1401, _T("Arabic (Algeria)") },
	{ 0x1407, _T("German (Liechtenstein)") },
	{ 0x1409, _T("English (New Zealand)") },
	{ 0x140A, _T("Spanish (Costa Rica)") },
	{ 0x140C, _T("French (Luxembourg)") },
	{ 0x1801, _T("Arabic (Morocco)") },
	{ 0x1809, _T("English (Ireland)") },
	{ 0x180A, _T("Spanish (Panama)") },
	{ 0x1C01, _T("Arabic (Tunisia)") },
	{ 0x1C09, _T("English (South Africa)") },
	{ 0x1C0A, _T("Spanish (Dominican Republic)") },
	{ 0x2001, _T("Arabic (Oman)") },
	{ 0x2009, _T("English (Jamaica)") },
	{ 0x200A, _T("Spanish (Venezuela)") },
	{ 0x2401, _T("Arabic (Yemen)") },
	{ 0x240A, _T("Spanish (Colombia)") },
	{ 0x2801, _T("Arabic (Syria)") },
	{ 0x2809, _T("English (Belize)") },
	{ 0x280A, _T("Spanish (Peru)") },
	{ 0x2C01, _T("Arabic (Jordan)") },
	{ 0x2C09, _T("English (Trinidad)") },
	{ 0x2C0A, _T("Spanish (Argentina)") },
	{ 0x3001, _T("Arabic (Lebanon)") },
	{ 0x300A, _T("Spanish (Ecuador)") },
	{ 0x3401, _T("Arabic (Kuwait)") },
	{ 0x340A, _T("Spanish (Chile)") },
	{ 0x3801, _T("Arabic (U.A.E.)") },
	{ 0x380A, _T("Spanish (Uruguay)") },
	{ 0x3C01, _T("Arabic (Bahrain)") },
	{ 0x3C0A, _T("Spanish (Paraguay)") },
	{ 0x4001, _T("Arabic (Qatar)") },
	{ 0x400A, _T("Spanish (Bolivia)") },
	{ 0x440A, _T("Spanish (El Salvador)") },
	{ 0x480A, _T("Spanish (Honduras)") },
	{ 0x4C0A, _T("Spanish (Nicaragua)") },
	{ 0x500A, _T("Spanish (Puerto Rico)") },
};
	
class CDotXkeymacs  
{
public:
	static void RemoveKey(const int nApplicationID, const int nCommandType, const int nKey);
	static void RemoveKey(const int nIndex, const int nApplicationID, const int nCommandType, const int nKey);
	static CString GetFunctionDefinition(int nIndex);
	static int GetIndex(int nApplicationID, int nCommandType, int nKey);
	static void GetKey(int nIndex, int nApplicationID, int nKeyID, int *pCommandType, int *pKey);
	static int GetKeyNumber(int nIndex, int nApplicationID);
	static int GetIndex(CString szSymbol);
	static void SetKey(int nIndex, int nApplicationID, int nCommandType, int nKey);
	static void ClearKey(int nIndex, int nApplicationID);
	static CString GetFunctionDefinition(CString szSymbol);
	static CString GetFunctionSymbol(int nIndex);
	static int GetFunctionNumber();
	static void Load();
	CDotXkeymacs();
	virtual ~CDotXkeymacs();

private:
	static LPCTSTR GetLanguage();
	static const TCHAR m_szExt[];
	static int m_nIndex[MAX_APP][MAX_COMMAND_TYPE][MAX_KEY];
	static void ClearFunctionDefinition();
	static CString GetDefinition(CString szFunctionDefinition);
	static CString GetSymbol(CString szFunctionDefinition);
	static BOOL IsFunctionDefinition(CString szFunctionDefinition);
	static CObList m_oFunctionDefinition;
	static void LoadUserData(LPCTSTR lpszFileName);
	static void LoadMainData(LPCTSTR lpszFileName);
	static void Load(LPCTSTR lpszFileName);
};

#endif // !defined(AFX_DOTXKEYMACS_H__0538C427_5733_47DA_B2C6_2E957EEFC59D__INCLUDED_)
