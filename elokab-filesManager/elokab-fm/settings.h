#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QStringList>
#define SORT_BY_NAME 0
#define ICON_VIEW_MODE 0
/**
 * @brief The Settings class اعدادات المستخدم
 */
class Settings : public QSettings
{
          Q_OBJECT
     public:

           //!
          explicit Settings(QObject *parent = 0):
               QSettings("elokab","elokabFm", parent)
          {
               beginGroup("Main");
          }

     signals:

          /*!< تغير الترتيب */
          void sortingChanged();

          /*!< رسالة بتغير حجم الايقونات */
          void iconSizeChanged(int);

          /*!< رسالة بتغير الملفات المخفية */
          void showHiddenChanged(bool);

          /*!< رسالة بتغير طريقة العرص */
          void viewModeChanged(int);

          /*!< عرض اخفاء التنقل الشجري */
          void showFolderNavigationChanged(bool);

          /*!< رسالة بعرص اواخفاء المعلومات */
          void showInformationChanged(bool);

          /*!< رسالة بعرص او اخفاء الازرار القياسية */
          void showToolbarChanged(bool);

          /*!< رسالة بعرص او اخفاء الطرفية */
          void showTerminalToolChanged(bool);

          /*!< رسالة بعرص او اخفاء القائمة الرئيسية */
          void showMenuBarChanged(bool);

          /*!< عرض اخفاء المصغرات */
          void showThumbnailsChanged(bool);

           /*!< عرض ايقونات بسيطة  */
 void showStandardIconsChanged(bool);

          /*!< اسم الطرفية الافتراضي */
          void terminalNameChanged(const QString &);

          /*!< تفعيل الملفات والمجلدات بنقرة واحدة */
          void singleclickChanged();

          /*!< اظهار خطوط الشجرة */
          void rootDecorationChanged(bool);

     private:


     public slots:
          /*!< حجم الايقونات */
          int  viewIconSize(){return value("ViewIconSize",48).toInt();}
          int  treeIconSize(){return value("TreeIconSize",24).toInt();}
          void setIconSize(int arg){emit iconSizeChanged(arg);}

          /*!< ترتيب حسب الاسم ام النوع ام التاريخ */
          int  sortBy(){return value("SortBy",SORT_BY_NAME).toInt();}
          void setSortBy(int arg){ setValue("SortBy",arg);emit sortingChanged();}

          /*!< عرض ايقونات ام تفلصسل ام قياسي */
          int  viewMode(){return value("ViewMode",ICON_VIEW_MODE).toInt();}
          void setViewMode(int arg){ setValue("ViewMode",arg);emit viewModeChanged(arg);}

          /*!< قائمة الازرار في اللوحة القياسية */
          QStringList listActions(){return value("ListActions",QStringList()
                                                 <<"Go_Back_Act"
                                                 <<"Go_Forward_Act"
                                                 <<"Go_Up_Act"
                                                 <<"Separator"
                                                 <<"Path_Edit_Act"
                                                 <<"Separator"
                                                 <<"Icon_View_Act"
                                                 <<"Detail_View_Act"
                                                 <<"Compact_View_Act").toStringList();}
          void setListActions(QStringList list){setValue("ListActions",list);}

          /*!< عرض اخفاء التنقل الشجري */
          bool folderNavigation(){return value("FolderNavigation",false).toBool();}
          void setFolderNavigation(const bool &arg){   setValue("FolderNavigation",arg);emit showFolderNavigationChanged(arg);}

          /*!< لوحة المعلومات */
          bool showInformation(){return value("ShowInformation",true).toBool();}
          void setShowInformation(const bool &arg){setValue("ShowInformation",arg);emit showInformationChanged(arg);}

          /*!< عرض اخفاء لوحة الادوات */
          bool showToolbar(){return value("ShowToolbar",true).toBool();}
          void setShowToolbar(const bool &arg){  setValue("ShowToolbar",arg);emit showToolbarChanged(arg);}

          /*!< عرض اخفاء الطرفية */
          bool showTerminalTool(){return value("ShowTerminalTool",false).toBool();}
          void setShowTerminalTool(const bool &arg){  setValue("ShowTerminalTool",arg);emit showTerminalToolChanged(arg);}

          /*!< عرض اخفاء القائمة الرئيسية */
          bool showMenuBar(){return value("ShowMenuBar",true).toBool();}
          void setShowMenuBar(const bool &arg){   setValue("ShowMenuBar",arg);emit showMenuBarChanged(arg);}

          /*!< عرض اخفاء المصغرات */
          bool showThumbnails(){return value("ShowThumbnails",false).toBool();}
          void setshowThumbnails(const bool &arg){  setValue("ShowThumbnails",arg);emit showThumbnailsChanged(arg);}

          /*!< عرض  ايقونات بسيطة */
          bool showStandardIcons(){return value("StandardIcons",false).toBool();}
          void setshowStandardIcons(const bool &arg){  setValue("StandardIcons",arg);emit showStandardIconsChanged(arg);}

          /*!< عرص اخفاء الملفات المخفية */
          bool showHidden(){return value("ShowHidden",false).toBool();}
          void setShowHidden(const bool &arg){setValue("ShowHidden",arg);emit showHiddenChanged(arg);}

          /*!< ترتيب تنازلي ام تصاعدي */
          bool sortAscending(){ return value("SortAscending",true).toBool();  }
          void  setSortAscending(const bool &arg){ setValue("SortAscending",arg);emit sortingChanged();}
          Qt::SortOrder sortOrder(){

               if(sortAscending())
                    return  Qt::AscendingOrder;
               else
                    return Qt::DescendingOrder;

          }

          /*!< اسم الطرفية الافتراضي */
          QString terminal(){return value("Terminal","x-terminal-emulator").toString();;}
          void setTerminal(const QString &arg){setValue("Terminal",arg);emit terminalNameChanged(arg);}

          /*!< تفعيل الملفات والكجلدات بنقرة واحدة */
          bool isSingleclick(){return value("Singleclick",false).toBool();}
          void setSingleclick(const bool &arg){setValue("Singleclick",arg);emit singleclickChanged();}

          /*!< اظهار خطوط الشجرة */
          bool rootIsDecorated(){return value("RootIsDecorated",true).toBool();}
          void setRootIsDecorated(const bool &arg){setValue("RootIsDecorated",arg);emit rootDecorationChanged(arg);}

     private slots:



};

#endif // SETTINGS_H
