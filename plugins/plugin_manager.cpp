#include "plugin_manager.h"
#include "pluginmanagerprivate.h"
#include "plugin.h"

#include <QDir>
#include <QApplication>
#include <QLibrary>

PluginManager *PluginManager::instance()
{

}

void PluginManager::loadAll()
{
    //������Ŀ¼
    QDir path = QDir(qApp->applicationDirPath());
    path.cd("plugins");

    //��ʼ������е�Ԫ����
    foreach (QFileInfo info, path.entryInfoList(QDir::Files | QDir::NoDotAndDotDot)) {
       scan(info.absoluteFilePath());
    }

    //���ز��
    foreach (QFileInfo info, path.entryInfoList(QDir::Files | QDir::NoDotAndDotDot)) {
        load(info.absoluteFilePath());
    }
}

void PluginManager::scan(const QString &path)
{
/***
 *�ж��Ƿ��ǿ⣨��׺��Ч�ԣ�
 * Windows��.dll��.DLL
 * Unix/Linux��.so
*/
    if (! QLibrary::isLibrary(path))
        return;

    //��ȡԪ���ݣ����ơ��汾��������
    QPluginLoader *loader = new QPluginLoader(path);
    //QJsonObject json = loader->metaData().value("MetaData").toObject;

    d->m_names.insert(path, json.value("name").toVariant());
    d->m_versions.insert(path, json.value("version").toVariant());
    d->m_dependencies.insert(path, json.value("dependencies").toArray().toVariantList());

    delete loader;
    loader = Q_NULLPTR;
}

void PluginManager::load(const QString &path)
{
    //�ж��Ƿ��ǿ�
    if (!QLibrary::isLibrary(path))
        return;

    //���������
    if (!d->check(path))
        return;

    //���ز��
    QPluginLoader *loader = new QPluginLoader(path);
    if (loader->load()) {
        //����̳���Plugin, ����Ϊ���Լ��Ĳ������ֹ�ⲿ���ע�룩��
        Plugin *plugin = qobject_cast<Plugin *>(loader->instance());
        if (plugin) {
            d->m_loaders.insert(path, loader);
        } else {
            delete loader;
            loader = Q_NULLPTR;
        }
    }
}

void PluginManager::unloadAll()
{
    foreach (const QString &path, d->m_loaders.keys()) {
        unload(path);
    }
}

void PluginManager::unload(const QString &path)
{
    QPluginLoader *loader = d->m_loaders.value(path);

    //ж�ز��, �����ڲ����ݽṹ���Ƴ�
    if (loader->unload()) {
        d->m_loaders.remove(path);
        delete loader;
        loader = Q_NULLPTR;
    }
}

QList<QPluginLoader *> PluginManager::plugins()
{
    return d->m_loaders.values();
}

PluginManager::PluginManager(QObject *parent)
    : QObject(parent)
{

}

PluginManager::~PluginManager()
{

}
