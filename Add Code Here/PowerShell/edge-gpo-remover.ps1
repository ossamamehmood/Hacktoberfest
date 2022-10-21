function RegKey-Changed(){
    try {
        write-host("Checking if Registry changed..")
        Get-ItemProperty -Path "HKCU:\Software\Policies\Microsoft\Edge\" -Name "AllowSurfGame" -ErrorAction Stop
        return $true
    }catch{
        write-host("Nothing to do...")
        return $false

    }

}

function Delete-GPORegKeysANDValues(){

    $RegRootEdge =  "HKCU:\Software\Policies\Microsoft\Edge"
    $WhiteListKeys = "AutoSelectCertificateForUrls ExemptDomainFileTypePairsFromFileTypeDownloadWarnings LegacySameSiteCookieBehaviorEnabledForDomainList OverrideSecurityRestrictionsOnInsecureOrigin PopupsAllowedForUrls SecurityKeyPermitAttestation SpellcheckLanguage"
    $WhiteListVals ="AuthNegotiateDelegateAllowlist AuthServerAllowlist DefaultSearchProviderSearchURL DefaultSearchProviderSuggestURL InternetExplorerIntegrationSiteList NewTabPageLocation DefaultSearchProviderEnabled DefaultSearchProviderName InternetExplorerIntegrationLevel"

    $RegValsRoot = Get-ItemProperty -Path $RegRootEdge

    #start deleting all values exluding $whitelistvals

    $RegValsRoot.PSObject.Properties | ForEach-Object {
    
        if(!$WhiteListVals.Contains( $_.Name) -and !$_.Name.startswith("PS") ){
            "Deleting Values: " + $_.Name #deletes value
            Remove-ItemProperty -Path $RegRootEdge -Name $_.Name
        }
    
    }

    #start deleting all keys exluding $whitelistkeys

    Get-ChildItem $RegRootEdge | 
        ForEach-Object {
            $currentkey = $_.ToString()

            if(!$WhiteListKeys.Contains($currentkey.Split('\')[-1])){
                write-host("Deleting Keys: " + $_) #deletes key
                Remove-Item -Path "Registry::$_"
            }
    } 
}


 while(1)
{
   if(RegKey-Changed){
    start-sleep -seconds 2
    Delete-GPORegKeysANDValues
   }
   start-sleep -seconds 20
}
pause