#ifndef PLUGINMANAGERPRIVATE_H
#define PLUGINMANAGERPRIVATE_H

#include <QVariant>
#include <QHash>

class QPluginLoader;

class PluginManagerPrivate
{
public:
    PluginManagerPrivate();
    bool check(const QString& path); //���������

    QHash<QString, QVariant> m_name; //���·�� - ����
    QHash<QString, QVariant> m_versions; //���·�� - �汾
    QHash<QString, QVariantList> m_dependencies; //���·�� - ����������Ĳ��
    QHash<QString, QPluginLoader *> m_loaders; //���·�� - QPluginLoaderʵ��
};

#endif // PLUGINMANAGERPRIVATE_H
