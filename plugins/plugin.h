#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>

#define PluginInterface_iid "com.Animation.PluginInterface"
/**
  *����һ������ӿ��࣬�����Ĳ�����̳��������ò������Ϊһ�����麯��
*/
class Plugin : public QObject
{
    Q_OBJECT
public:
    Plugin() {}
    virtual ~Plugin() {}
//    virtual QString toolName() const = 0;
};

Q_DECLARE_INTERFACE(Plugin, PluginInterface_iid)    //�� Plugin�ӿ���Ψһ��ʶ��һ�𹫿�

#endif // PLUGIN_H
