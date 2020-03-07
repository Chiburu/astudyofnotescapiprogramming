# インクルードファイル

INCLUDEPATH += $${NOTES_C_API_PATH}/include
DEPENDPATH += $${NOTES_C_API_PATH}/include

# ライブラリファイル

LIBS += -lnotes

# マクロ

DEFINES += PRODUCTION_VERSION

# Windows
win32 {
  DEFINES += W32 W NT

  # 64bit
  contains(QMAKE_TARGET.arch, x86_64) {
    DEFINES += W64 ND64 _AMD64_
    LIBS += -L$${NOTES_C_API_PATH}/lib/mswin64
  }
  # 32bit
  else {
    DEFINES += _X86_
    LIBS += -L$${NOTES_C_API_PATH}/lib/mswin32
  }
}
