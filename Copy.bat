attrib				-R			.\Reference\Headers\*.*
xcopy				/y /s		.\Engine\Public\*.*					.\Reference\Headers\
attrib				+R			.\Reference\Headers\*.*

xcopy				/y /s		.\Engine\ThirdPartyLib\*.*			.\Reference\Librarys\
