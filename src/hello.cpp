#include "hello.h"

#include "ui_hello.h"

hello::hello(QWidget* parent) : QDialog(parent), ui(new Ui::hello) {
    ui->setupUi(this);
    ui->time_modal_setting->addItem("year,month,day,ndays");
    ui->time_modal_setting->addItem("year,doy,,ndays");
    ui->time_modal_setting->addItem("GPSweek,dow,,ndays");

    this->check_list.push_back("no");
    this->check_list.push_back("yes");

    ui->minus_add_day_setting->addItems(check_list);

    ui->merge_sp3_setting->addItems(check_list);

    ui->print_wget_log_setting->addItems(check_list);

    ui->ftp_download_setting->addItems(check_list);

    ui->obs_download_setting->addItems(check_list);

    ui->nav_download_setting->addItems(check_list);

    ui->orb_clk_download_setting->addItems(check_list);

    ui->erp_eop_download_setting->addItems(check_list);

    ui->obx_download_setting->addItems(check_list);

    ui->dsb_download_setting->addItems(check_list);

    ui->osb_download_setting->addItems(check_list);

    ui->snx_download_setting->addItems(check_list);

    ui->ion_download_setting->addItems(check_list);

    ui->trop_download_setting->addItems(check_list);

    ui->roti_download_setting->addItems(check_list);

    ui->atx_download_setting->addItems(check_list);

    init_exist_list();

    Config::init_GUI(&this->prop, &this->fpop);
}

hello::~hello() { delete ui; }

void hello::init_exist_list() {
    name_length_list.push_back("long name");
    name_length_list.push_back("short name");
    name_length_list.push_back("long and short name");

    ftp_site_list.push_back("cddis");
    ftp_site_list.push_back("ign");
    ftp_site_list.push_back("whu");
    ui->ftp_download_site_setting->addItem("");
    ui->ftp_download_site_setting->addItems(this->ftp_site_list);

    obs_type_list.push_back("daily");
    obs_type_list.push_back("hourly");
    obs_type_list.push_back("highrate");
    obs_type_list.push_back("30s");
    obs_type_list.push_back("5s");
    obs_type_list.push_back("1s");
    ui->obs_type_setting->addItem("");
    ui->obs_type_setting->addItem(obs_type_list[0]);
    ui->obs_type_setting->addItem(obs_type_list[1]);
    ui->obs_type_setting->addItem(obs_type_list[2]);

    obs_process_site_list.push_back("igs");
    obs_process_site_list.push_back("mgex");
    obs_process_site_list.push_back("igm");
    obs_process_site_list.push_back("cut");
    obs_process_site_list.push_back("hk");
    obs_process_site_list.push_back("ngs");
    obs_process_site_list.push_back("epn");
    obs_process_site_list.push_back("pbo");
    obs_process_site_list.push_back("chi");
    ui->obs_pro_site_setting->addItem("");
    ui->obs_pro_site_setting->addItems(this->obs_process_site_list);

    ui->obs_site_setting->addItem("");
    ui->obs_site_setting->addItem("all");
    ui->obs_site_setting->addItem("...");

    ui->obs_name_length_setting->addItems(name_length_list);

    ui->nav_type_setting->addItem("");
    ui->nav_type_setting->addItem("daily");
    ui->nav_type_setting->addItem("hourly");

    nav_system_list.push_back("gps");
    nav_system_list.push_back("glo");
    nav_system_list.push_back("bds");
    nav_system_list.push_back("gal");
    nav_system_list.push_back("qzs");
    nav_system_list.push_back("irn");
    nav_system_list.push_back("mixed3");
    nav_system_list.push_back("mixed4");
    nav_system_list.push_back("all");

    ui->nav_system_setting->addItem("");
    ui->nav_system_setting->addItem(this->nav_system_list[0]);
    ui->nav_system_setting->addItem(this->nav_system_list[1]);
    ui->nav_system_setting->addItem(this->nav_system_list[6]);
    ui->nav_system_setting->addItem(this->nav_system_list[7]);

    nav_process_site_list.push_back("igs");
    nav_process_site_list.push_back("dlr");
    nav_process_site_list.push_back("ign");

    ui->nav_pro_site_setting->addItem("");
    ui->nav_pro_site_setting->addItem(this->nav_process_site_list[0]);
    ui->nav_pro_site_setting->addItem(this->nav_process_site_list[1]);

    ui->nav_name_length_setting->addItems(name_length_list);

    orb_clk_process_site_list.push_back("cod");
    orb_clk_process_site_list.push_back("emr");
    orb_clk_process_site_list.push_back("esa");
    orb_clk_process_site_list.push_back("gfz");
    orb_clk_process_site_list.push_back("grg");
    orb_clk_process_site_list.push_back("igs");
    orb_clk_process_site_list.push_back("jgx");
    orb_clk_process_site_list.push_back("jpl");
    orb_clk_process_site_list.push_back("mit");
    orb_clk_process_site_list.push_back("all");
    orb_clk_process_site_list.push_back("cod_m");
    orb_clk_process_site_list.push_back("gfz_m");
    orb_clk_process_site_list.push_back("grg_m");
    orb_clk_process_site_list.push_back("iac_m");
    orb_clk_process_site_list.push_back("jax_m");
    orb_clk_process_site_list.push_back("sha_m");
    orb_clk_process_site_list.push_back("whu_m");
    orb_clk_process_site_list.push_back("all_m");
    orb_clk_process_site_list.push_back("cod_r");
    orb_clk_process_site_list.push_back("emr_r");
    orb_clk_process_site_list.push_back("esa_r");
    orb_clk_process_site_list.push_back("gfz_r");
    orb_clk_process_site_list.push_back("igs_r");
    orb_clk_process_site_list.push_back("esa_u");
    orb_clk_process_site_list.push_back("gfz_u");
    orb_clk_process_site_list.push_back("igs_u");
    orb_clk_process_site_list.push_back("whu_u");
    orb_clk_process_site_list.push_back("cnt");
    ui->orb_clk_pro_site_setting->addItem("");
    ui->orb_clk_pro_site_setting->addItems(orb_clk_process_site_list);

    ui->orb_clk_name_length_setting->addItems(name_length_list);

    erp_eop_process_site_list.push_back("cod");
    erp_eop_process_site_list.push_back("emr");
    erp_eop_process_site_list.push_back("esa");
    erp_eop_process_site_list.push_back("gfz");
    erp_eop_process_site_list.push_back("grg");
    erp_eop_process_site_list.push_back("igs");
    erp_eop_process_site_list.push_back("jgx");
    erp_eop_process_site_list.push_back("jpl");
    erp_eop_process_site_list.push_back("mit");
    erp_eop_process_site_list.push_back("esa_u");
    erp_eop_process_site_list.push_back("gfz_u");
    erp_eop_process_site_list.push_back("igs_u");
    ui->erp_eop_pro_site_setting->addItem("");
    ui->erp_eop_pro_site_setting->addItems(erp_eop_process_site_list);

    ui->erp_eop_name_length_setting->addItems(name_length_list);

    ui->obx_pro_site_setting->addItem("");
    ui->obx_pro_site_setting->addItem("cod");
    ui->obx_pro_site_setting->addItem("gfz");
    ui->obx_pro_site_setting->addItem("grg");
    ui->obx_pro_site_setting->addItem("whu");
    ui->obx_pro_site_setting->addItem("all");
    ui->obx_pro_site_setting->addItem("cnt");

    ui->dsb_pro_site_setting->addItem("");
    ui->dsb_pro_site_setting->addItem("cod");
    ui->dsb_pro_site_setting->addItem("cas");
    ui->dsb_pro_site_setting->addItem("all");

    ui->osb_pro_site_setting->addItem("");
    ui->osb_pro_site_setting->addItem("cas");
    ui->osb_pro_site_setting->addItem("cod");
    ui->osb_pro_site_setting->addItem("gfz");
    ui->osb_pro_site_setting->addItem("grg");
    ui->osb_pro_site_setting->addItem("whu");
    ui->osb_pro_site_setting->addItem("all");
    ui->osb_pro_site_setting->addItem("cnt");

    ui->snx_name_length_setting->addItems(name_length_list);

    ui->ion_pro_site_setting->addItem("");
    ui->ion_pro_site_setting->addItem("cas");
    ui->ion_pro_site_setting->addItem("cod");
    ui->ion_pro_site_setting->addItem("emr");
    ui->ion_pro_site_setting->addItem("esa");
    ui->ion_pro_site_setting->addItem("igs");
    ui->ion_pro_site_setting->addItem("jpl");
    ui->ion_pro_site_setting->addItem("upc");
    ui->ion_pro_site_setting->addItem("all");

    ui->ion_name_length_setting->addItems(name_length_list);

    ui->trop_pro_site_setting->addItem("");
    ui->trop_pro_site_setting->addItem("cod");
    ui->trop_pro_site_setting->addItem("igs");

    ui->trop_name_length_setting->addItems(name_length_list);
}

void hello::on_pushButton_clicked() {
    QString file_name = QFileDialog::getOpenFileName(this, tr("配置文件选择"), "/home", tr("配置文件(*.yaml)"));
    if (!file_name.isEmpty()) {
        this->Location = file_name.toStdString();
        ui->Location_Label->setText(file_name);
        QFileInfo main_dir(file_name);
        if (main_dir.exists()) {
            this->location_main_dir = main_dir.absolutePath().toStdString();
            //            qDebug() << QString::fromStdString(location_main_dir);
        }
    }
}

bool hello::Start_Download(const std::string& Loc) {
    Config::run(Loc);
    return 1;
}

void hello::set_dir() {
    this->prop.maindir = ui->main_dir_location->text().toStdString();
    this->prop.obsdir = ui->main_dir_location->text().toStdString() + "/obs";
    this->prop.navdir = ui->main_dir_location->text().toStdString() + "/nav";
    this->prop.orbdir = ui->main_dir_location->text().toStdString() + "/orb";
    this->prop.clkdir = ui->main_dir_location->text().toStdString() + "/clk";
    this->prop.eopdir = ui->main_dir_location->text().toStdString() + "/eop";
    this->prop.obxdir = ui->main_dir_location->text().toStdString() + "/obx";
    this->prop.biadir = ui->main_dir_location->text().toStdString() + "/bia";
    this->prop.snxdir = ui->main_dir_location->text().toStdString() + "/snx";
    this->prop.iondir = ui->main_dir_location->text().toStdString() + "/ion";
    this->prop.ztddir = ui->main_dir_location->text().toStdString() + "/ztd";
    this->prop.tbldir = ui->main_dir_location->text().toStdString() + "/tbl";
    this->prop.logdir = ui->main_dir_location->text().toStdString() + "/log";
    this->prop.logfil = prop.logdir + "/log.txt";
    // third-party location remains specified
}

void hello::on_config_download_clicked() {
    if (this->Start_Download(this->Location)) {
        //        QDialog msg(this);
        //        msg.setModal(true);
        //        QLabel label(&msg);
        //        label.setText("Done!");
        //        msg.show();
    }
}

void hello::on_main_dir_check_clicked() {
    QString dir_name = QFileDialog::getExistingDirectory(this, tr("主目录选择"), QDir::currentPath());
    if (!dir_name.isEmpty()) {
        this->location_main_dir = dir_name.toStdString();
        //        ui->Location_Label->setText(dir_name);
        ui->main_dir_location->setText(dir_name);
    }
    //    this->location_main_dir = ui->main_dir_location->text().toStdString();
    //    qDebug() << QString::fromStdString(this->location_main_dir);
}

void hello::on_time_modal_setting_activated(const QString& arg1) {
    if (arg1 == QString("year,month,day,ndays")) {
        ui->day_edit->setEnabled(true);
        this->time_modal = 1;
    } else if (arg1 == QString("year,doy,,ndays")) {
        ui->day_edit->setEnabled(false);
        this->time_modal = 2;
    } else if (arg1 == QString("GPSweek,dow,,ndays")) {
        ui->day_edit->setEnabled(false);
        this->time_modal = 3;
    }
}

void hello::on_minus_add_day_setting_activated(int index) { this->fpop.minus_add_1day = index; }

void hello::on_merge_sp3_setting_activated(int index) { this->fpop.merge_sp3files = index; }

void hello::on_print_wget_log_setting_activated(int index) { this->fpop.printinfo4wget = index; }

void hello::on_ftp_download_setting_activated(int index) { this->fpop.ftpdownloading = index; }

void hello::on_ftp_download_site_setting_activated(const QString& arg1) {
    if (arg1 == "cddis" || arg1 == "whu") {
        ui->nav_pro_site_setting->clear();
        ui->nav_pro_site_setting->addItem("");
        ui->nav_pro_site_setting->addItem(this->nav_process_site_list[0]);
        ui->nav_pro_site_setting->addItem(this->nav_process_site_list[1]);
    } else if (arg1 == "ign") {
        ui->nav_pro_site_setting->clear();
        ui->nav_pro_site_setting->addItem("");
        ui->nav_pro_site_setting->addItem(this->nav_process_site_list[0]);
        ui->nav_pro_site_setting->addItem(this->nav_process_site_list[2]);
    }
    this->fpop.ftpfrom = arg1.toStdString();
}

void hello::on_obs_download_setting_activated(int index) { this->fpop.getobs = index; }

void hello::on_obs_type_setting_activated(const QString& arg1) {
    this->fpop.obstype = arg1.toStdString();
    if (arg1 == "daily") {
        ui->obs_start_time->setEnabled(false);
        ui->obs_consecutive_time->setEnabled(false);
    } else {
        ui->obs_start_time->setEnabled(true);
        ui->obs_consecutive_time->setEnabled(true);
    }
}

void hello::on_obs_pro_site_setting_activated(const QString& arg1) {
    if (arg1 == "igs" || arg1 == "mgex" || arg1 == "igm") {
        ui->obs_type_setting->clear();
        ui->obs_type_setting->addItem("");
        ui->obs_type_setting->addItem(obs_type_list[0]);
        ui->obs_type_setting->addItem(obs_type_list[1]);
        ui->obs_type_setting->addItem(obs_type_list[2]);
    } else if (arg1 == "cut" || arg1 == "ngs" || arg1 == "epn" || arg1 == "pbo") {
        ui->obs_type_setting->clear();
        ui->obs_type_setting->addItem("");
        ui->obs_type_setting->addItem(obs_type_list[0]);
    } else if (arg1 == "hk") {
        ui->obs_type_setting->clear();
        ui->obs_type_setting->addItem("");
        ui->obs_type_setting->addItem(obs_type_list[3]);
        ui->obs_type_setting->addItem(obs_type_list[4]);
        ui->obs_type_setting->addItem(obs_type_list[5]);
    }
}

void hello::on_obs_site_setting_activated(int index) {
    if (ui->obs_site_setting->itemText(index) == "all") {
        this->fpop.obslist = this->location_main_dir + "/" + ui->obs_site_setting->currentText().toStdString();
    } else if (ui->obs_site_setting->itemText(index) == "...") {
        QString site_list_loc = QFileDialog::getOpenFileName(
            this, tr("obs站点文件选择"), QString::fromStdString(this->location_main_dir), tr("obs站点文件(*.list)"));
        if (!site_list_loc.isEmpty()) {
            //            qDebug() << site_list_loc;
            this->fpop.obslist = site_list_loc.toStdString();
        }
    }
}

void hello::on_obs_name_length_setting_activated(int index) { this->fpop.l2s4obs = index; }

void hello::on_nav_download_setting_activated(int index) { this->fpop.getnav = index; }

void hello::on_nav_type_setting_activated(const QString& arg1) {
    if (arg1 == "daily") {
        this->fpop.navtype = arg1.toStdString();
        ui->nav_site_choose_button->setEnabled(false);
        ui->nav_start_time->setEnabled(false);
        ui->nav_consecutive_time->setEnabled(false);
        ui->nav_system_setting->clear();
        ui->nav_system_setting->addItem("");
        ui->nav_system_setting->addItem(this->nav_system_list[0]);
        ui->nav_system_setting->addItem(this->nav_system_list[1]);
        ui->nav_system_setting->addItem(this->nav_system_list[6]);
        ui->nav_system_setting->addItem(this->nav_system_list[7]);
    } else if (arg1 == "hourly") {
        this->fpop.navtype = arg1.toStdString();
        ui->nav_site_choose_button->setEnabled(true);
        ui->nav_start_time->setEnabled(true);
        ui->nav_consecutive_time->setEnabled(true);
        ui->nav_system_setting->clear();
        ui->nav_system_setting->addItem("");
        ui->nav_system_setting->addItems(this->nav_system_list);
    }
}

void hello::on_nav_system_setting_activated(const QString& arg1) { this->fpop.navsys = arg1.toStdString(); }

void hello::on_nav_pro_site_setting_activated(const QString& arg1) { this->fpop.navfrom = arg1.toStdString(); }

void hello::on_nav_site_choose_button_clicked() {
    QString site_list_loc = QFileDialog::getOpenFileName(
        this, tr("nav站点文件选择"), QString::fromStdString(this->location_main_dir), tr("nav站点文件(*.list)"));
    if (!site_list_loc.isEmpty()) {
        //            qDebug() << site_list_loc;
        ui->nav_site_list_location->setText(site_list_loc);
        this->fpop.navlist = site_list_loc.toStdString();
    }
}

void hello::on_nav_name_length_setting_activated(int index) { this->fpop.l2s4nav = index; }

void hello::on_orb_clk_download_setting_activated(int index) { this->fpop.getorbclk = index; }

void hello::on_orb_clk_pro_site_setting_activated(int index) {
    if (index == 1 || index == 2 || index == 3 || index == 4 || index == 5 || index == 6 || index == 7 || index == 8 ||
        index == 9 || index == 11 || index == 12 || index == 13 || index == 14 || index == 15 || index == 16 ||
        index == 17) {
        if (this->orb_clk_add_count == 0) {
            ui->orb_clk_site_list->clear();
            ui->orb_clk_site_list->setText(this->orb_clk_process_site_list[index - 1]);
            this->orb_clk_add_count++;
        } else {
            ui->orb_clk_site_list->setText(ui->orb_clk_site_list->text() + "+" +
                                           this->orb_clk_process_site_list[index - 1]);
        }
        ui->orb_clk_start_time->setEnabled(false);
        ui->orb_clk_consecutive_time->setEnabled(false);
    } else {
        ui->orb_clk_site_list->setText(this->orb_clk_process_site_list[index - 1]);
        this->orb_clk_add_count = 0;
        ui->orb_clk_start_time->setEnabled(true);
        ui->orb_clk_consecutive_time->setEnabled(true);
    }
}

void hello::on_orb_clk_clear_clicked() {
    ui->orb_clk_site_list->clear();
    this->orb_clk_add_count = 0;
}

void hello::on_orb_clk_name_length_setting_activated(int index) { this->fpop.l2s4oc = index; }

void hello::on_erp_eop_download_setting_activated(int index) { this->fpop.geteop = index; }

void hello::on_erp_eop_pro_site_setting_activated(int index) {
    if (index == 10 || index == 11 || index == 12) {
        ui->erp_eop_start_time->setEnabled(true);
        ui->erp_eop_consecutive_time->setEnabled(true);
    } else {
        ui->erp_eop_start_time->setEnabled(false);
        ui->erp_eop_consecutive_time->setEnabled(false);
    }
}

void hello::on_erp_eop_name_length_setting_activated(int index) { this->fpop.l2s4eop = index; }

void hello::on_obx_download_setting_activated(int index) { this->fpop.getobx = index; }

void hello::on_obx_pro_site_setting_activated(int index) {
    this->fpop.obxfrom = ui->obx_pro_site_setting->itemText(index).toStdString();
}

void hello::on_dsb_download_setting_activated(int index) { this->fpop.getdsb = index; }

void hello::on_dsb_pro_site_setting_activated(int index) {
    this->fpop.dsbfrom = ui->dsb_pro_site_setting->itemText(index).toStdString();
}

void hello::on_osb_download_setting_activated(int index) { this->fpop.getosb = index; }

void hello::on_osb_pro_site_setting_activated(int index) {
    this->fpop.osbfrom = ui->osb_pro_site_setting->itemText(index).toStdString();
}

void hello::on_snx_download_setting_activated(int index) { this->fpop.getsnx = index; }

void hello::on_snx_name_length_setting_activated(int index) { this->fpop.l2s4snx = index; }

void hello::on_roti_download_setting_activated(int index) { this->fpop.getroti = index; }

void hello::on_ion_download_setting_activated(int index) { this->fpop.getion = index; }

void hello::on_ion_pro_site_setting_activated(int index) {
    if (ui->ion_pro_site_setting->itemText(index) == "all") {
        ui->ion_site_list->setText(ui->ion_pro_site_setting->itemText(index));
        this->ion_add_count = 0;
    } else {
        if (ion_add_count == 0) {
            ui->ion_site_list->clear();
            ui->ion_site_list->setText(ui->ion_pro_site_setting->itemText(index));
            this->ion_add_count++;
        } else {
            ui->ion_site_list->setText(ui->ion_site_list->text() + "+" + ui->ion_pro_site_setting->itemText(index));
        }
    }
}

void hello::on_ion_clear_clicked() {
    this->ion_add_count = 0;
    ui->ion_site_list->clear();
}

void hello::on_ion_name_length_setting_activated(int index) { this->fpop.l2s4ion = index; }

void hello::on_trop_download_setting_activated(int index) { this->fpop.gettrp = index; }

void hello::on_trop_pro_site_setting_activated(const QString& arg1) {
    if (arg1 == "igs")
        ui->trop_site_choose_button->setEnabled(true);
    else
        ui->trop_site_choose_button->setEnabled(false);
    this->fpop.trpfrom = arg1.toStdString();
}

void hello::on_trop_site_choose_button_clicked() {
    QString site_list_loc = QFileDialog::getOpenFileName(
        this, tr("trop站点文件选择"), QString::fromStdString(this->location_main_dir), tr("trop站点文件(*.list)"));
    if (!site_list_loc.isEmpty()) {
        ui->trop_site_list_location->setText(site_list_loc);
        this->fpop.trplist = site_list_loc.toStdString();
    }
}

void hello::on_trop_name_length_setting_activated(int index) { this->fpop.l2s4trp = index; }

void hello::on_atx_download_setting_activated(int index) { this->fpop.getatx = index; }

void hello::on_GUI_download_clicked() {
    set_dir();
    int j = this->time_modal;
    if (j == 1) /* year, month, day */
    {
        std::vector<double> ep;
        ep.push_back(ui->year_edit->text().toInt());
        ep.push_back(ui->month_edit->text().toInt());
        ep.push_back(ui->day_edit->text().toInt());
        ep.push_back(0);
        ep.push_back(0);
        ep.push_back(0);
        prop.ts = GTime::ymdhms2time(ep);
        prop.ndays = ui->ndays->text().toInt();
    } else if (j == 2) /* year, day of year */
    {
        prop.ts = GTime::yrdoy2time(ui->year_edit->text().toInt(), ui->month_edit->text().toInt());
        prop.ndays = ui->ndays->text().toInt();
    } else if (j == 3) /* GPS week, day within week */
    {
        double sow = ui->month_edit->text().toInt() * 86400;
        prop.ts = GTime::gpst2time(ui->year_edit->text().toInt(), sow);
        prop.ndays = ui->ndays->text().toInt();
    }
    /* obs download time setting */
    this->fpop.obsfrom = ui->obs_pro_site_setting->currentText().toStdString();
    int hh = ui->obs_start_time->text().toInt();
    int nh = ui->obs_consecutive_time->text().toInt();
    int imax = MIN(hh + nh, 24);
    int step = 1;
    for (int i = hh; i < imax; i++)
        this->fpop.hhobs.push_back(i);
    /* nav download time setting */
    hh = ui->nav_start_time->text().toInt();
    nh = ui->nav_consecutive_time->text().toInt();
    imax = MIN(hh + nh, 24);
    for (int i = hh; i < imax; i++)
        this->fpop.hhnav.push_back(i);
    /* orbclk download setting */
    this->fpop.orbclkfrom = ui->orb_clk_site_list->text().toStdString();
    hh = ui->orb_clk_start_time->text().toInt();
    nh = ui->orb_clk_consecutive_time->text().toInt();
    std::string ocopt = fpop.orbclkfrom;
    std::vector<std::string> acs;
    int ipos = (int)ocopt.find_first_of('+');
    if (ipos > 0)
        acs = CString::split(ocopt, "+");
    else
        acs.push_back(ocopt);
    fpop.hhorbclk.resize(4); /* for "esa_u", "gfz_u", "igs_u", and "whu_u" */
    for (size_t i = 0; i < acs.size(); i++) {
        std::string ac_i = acs[i];
        if (ac_i == "igs_u" || ac_i == "esa_u")
            step = 6;
        else if (ac_i == "gfz_u")
            step = 3;
        else if (ac_i == "whu_u")
            step = 1;
        else
            step = 24;
        int imax = 24;
        for (int i = 0; i < imax; i += step) {
            if (hh > i)
                hh = i + step;
            else
                break;
        }
        imax = MIN(hh + nh * step, 24);
        for (int i = hh; i < imax; i += step) {
            if (ac_i == "esa_u")
                fpop.hhorbclk[0].push_back(i);
            else if (ac_i == "gfz_u")
                fpop.hhorbclk[1].push_back(i);
            else if (ac_i == "igs_u")
                fpop.hhorbclk[2].push_back(i);
            else if (ac_i == "whu_u")
                fpop.hhorbclk[3].push_back(i);
        }
    }
    /* erp,eop download setting */
    this->fpop.eopfrom = ui->erp_eop_pro_site_setting->currentText().toStdString();
    hh = ui->erp_eop_start_time->text().toInt();
    nh = ui->erp_eop_consecutive_time->text().toInt();
    std::string eopt = fpop.eopfrom;
    if (eopt == "igs_u" || eopt == "esa_u")
        step = 6;
    else if (eopt == "gfz_u")
        step = 3;
    else
        step = 24;
    imax = 24;
    for (int i = 0; i < imax; i += step) {
        if (hh > i)
            hh = i + step;
        else
            break;
    }
    imax = MIN(hh + nh * step, 24);
    for (int i = hh; i < imax; i += step)
        fpop.hheop.push_back(i);
    /* ionosphreic download setting */
    this->fpop.ionfrom = ui->ion_site_list->text().toStdString();
    /* setting done! */

    if (fpop.ftpdownloading) {
        FtpUtil ftp;
        std::string obsdirmain = prop.obsdir;
        std::string navdirmain = prop.navdir;
        std::string iondirmain = prop.iondir;
        std::string ztddirmain = prop.ztddir;
        for (int i = 0; i < prop.ndays; i++) {
            int yyyy, doy;
            GTime::time2yrdoy(prop.ts, yyyy, doy);
            std::string syyyy = CString::int2str(yyyy, 4);
            std::string sdoy = CString::int2str(doy, 3);
            std::string dir, sep;
            sep.push_back((char)FILEPATHSEP);
            /* creat new observation sub-directory */
            if (fpop.getobs) {
                dir = obsdirmain + sep + syyyy + sep + sdoy;
                CString::trim(dir);
                prop.obsdir = dir;
                if (access(dir.c_str(), 0) == -1) {
                    /* If the directory does not exist, creat it */
#ifdef _WIN32 /* for Windows */
                    std::string cmd = "mkdir " + dir;
#else /* for Linux or Mac */
                    std::string cmd = "mkdir -p " + dir;
#endif
                    std::system(cmd.c_str());
                }
            }

            /* creat new NAV sub-directory */
            if (fpop.getnav) {
                dir = navdirmain + sep + syyyy + sep + sdoy;
                CString::trim(dir);
                prop.navdir = dir;
                if (access(dir.c_str(), 0) == -1) {
                    /* If the directory does not exist, creat it */
#ifdef _WIN32 /* for Windows */
                    std::string cmd = "mkdir " + dir;
#else /* for Linux or Mac */
                    std::string cmd = "mkdir -p " + dir;
#endif
                    std::system(cmd.c_str());
                }
            }

            /* creat new ION sub-directory */
            if (fpop.getion) {
                dir = iondirmain + sep + syyyy + sep + sdoy;
                CString::trim(dir);
                prop.iondir = dir;
                if (access(dir.c_str(), 0) == -1) {
                    /* If the directory does not exist, creat it */
#ifdef _WIN32 /* for Windows */
                    std::string cmd = "mkdir " + dir;
#else /* for Linux or Mac */
                    std::string cmd = "mkdir -p " + dir;
#endif
                    std::system(cmd.c_str());
                }
            }

            /* creat new ZTD sub-directory */
            if (fpop.gettrp) {
                dir = ztddirmain + sep + syyyy + sep + sdoy;
                CString::trim(dir);
                prop.ztddir = dir;
                if (access(dir.c_str(), 0) == -1) {
                    /* If the directory does not exist, creat it */
#ifdef _WIN32 /* for Windows */
                    std::string cmd = "mkdir " + dir;
#else /* for Linux or Mac */
                    std::string cmd = "mkdir -p " + dir;
#endif
                    std::system(cmd.c_str());
                }
            }
            /* the main entry of FTP downloader */
            ftp.FtpDownload(&prop, &fpop);

            prop.ts = GTime::TimeAdd(prop.ts, 86400.0);
        }
        ui->download_info->setText("Done!");
    }
}

void hello::on_choose_thirdparty_dir_clicked() {
    QString dir_name = QFileDialog::getExistingDirectory(this, tr("第三方路径选择"), ui->main_dir_location->text());
    if (!dir_name.isEmpty()) {
        this->prop.dir3party = dir_name.toStdString();
        //        this->location_main_dir = dir_name.toStdString();
        //        ui->Location_Label->setText(dir_name);
        ui->third_party_dir->setText(dir_name);
    }
}
