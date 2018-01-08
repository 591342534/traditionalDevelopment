#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include <QObject>

class QPluginLoader;
class PluginMangerPrivate;

class PluginManager : public QObject
{
    Q_OBJECT
public:
    static PluginManager* instance();
    void loadAll(); //�������в��
    void scan(const QString& path); //ɨ�������ļ������в��Ԫ����
    void load(const QString& path); //���ز��
    void unloadAll();   //ж�����в��
    void unload(const QString& path); //ж�ز��
    QList<QPluginLoader *> plugins(); //��ȡ���в��
private:
    explicit PluginManager(QObject *parent = nullptr);
    ~PluginManager();
private:
    static PluginManager *m_instance;
    PluginMangerPrivate *d;
signals:

public slots:
};

#endif // PLUGIN_MANAGER_H
