<?php

// Code Igniter HMVC module Generator
// how to use: php -f ci_generate_module.php [name1] or php -f ci_generate_module.php [name1] [name2]

if (!$argv[2] ){

	$name = $argv[1];

	echo "generate module... \n";
	$controllerLocation = "application/modules/" . ucfirst($name) . "/controllers";
	$viewsLocation = "application/modules/" .  ucfirst($name)  . "/views";
	$modelsLocation = "application/models";

	mkdir($controllerLocation, 0777, true);
	mkdir($viewsLocation, 0777, true);

	if ($controllerLocation) {

		$controller = fopen($controllerLocation . "/" . ucfirst($name) . ".php", "w+");
		$controllerContent = "<?php
		if (!defined('BASEPATH'))
			exit('No direct script access allowed');
		class " . ucfirst($name) . " extends MY_Controller {
			
			function __construct()
			{
				parent::__construct();
				\$this->load->library('form_validation');
				// \$this->load->model('m_".$name."');
				\$this->load->helper('url');
				\$this->load->helper('common_helper');
				// if (!\$this->session->userdata('is_login')) {
				// 	redirect('login');
				// }
				\$this->module = \$this->router->fetch_module();
				\$this->isi = ['header_custom' => \$this->module . '/v-header-custom', 'footer_custom' => \$this->module . '/v-footer-custom'];
			}
			function index()
			{
				\$data['page'] = 'monitoring';
				// \$this->isi['".$name."'] = \$this->m_".$name."->get_".$name."();
				\$this->isi['view_content']	= \$this->load->view('v-".$name."', '', TRUE);
				// var_dump(\$this->isi['view_content']);
				\$this->load->view('pages/v-main', \$this->isi);
			}
		}
		?>";

		if ($controller) {
			fwrite($controller, $controllerContent);
			fclose($controller);
		} else {
			echo "failed";
		}

		echo "Controller created..\n";
	} else {
		echo "Fail...\n";
	}

	if ($modelsLocation) {
		$models = fopen($modelsLocation . "/Mdl" . ucfirst($name) . ".php", "w+");

		$modelsContent = "<?php
		defined('BASEPATH') or exit('No direct script access allowed');
		class Mdl" . ucfirst($name) . " extends CI_Model {
			public function __construct() {
				parent::__construct();
			}
			public function get" . ucfirst($name) . "() {
				echo 'get" . ucfirst($name) . "';
			}
			
			public function update" . ucfirst($name) . "(\$data) {
				echo 'update" . ucfirst($name) . "';
			}
			public function add" . ucfirst($name) . "(\$data) {
				echo 'add" . ucfirst($name) . "';
			}
			public function delete" . ucfirst($name) . "(\$data) {
				echo 'delete" . ucfirst($name) . "';
			}
		}";

		if ($models) {
			fwrite($models, $modelsContent);
			fclose($models);
		} else {
			echo "failed";
		}

		echo "Controller created..\n";
	}
	if ($viewsLocation) {

		$vcontent = fopen($viewsLocation . "/v-" . $name . ".php", "w+");
		$vheader = fopen($viewsLocation . "/v-footer-custom.php", "w+");
		$vfooter = fopen($viewsLocation . "/v-header-custom.php", "w+");

		$viewContent = "<h2>" . $name . "</h2> ";
		$customContent = "<!-- VIEWS --> ";

		if ($vcontent) {
			fwrite($vcontent, $viewContent);
			fwrite($vheader, $customContent);
			fwrite($vfooter, $customContent);
			fclose($vcontent);
			fclose($vheader);
			fclose($vfooter);
		} else {
			echo "failed";
		}
		echo "View created..\n";

		echo "Finish ...\n";
	} else {
		echo "Fail...\n";
	}

} else {
	// NAMA LEBIH DARI 1 KATA
	
	$name = $argv[1];
	$name2 = $argv[2];

	echo "generate module... \n";
	$controllerLocation = "application/modules/" .  ucfirst($name) . ucfirst($name2)."/controllers";
	$viewsLocation = "application/modules/" .  ucfirst($name) . ucfirst($name2) . "/views";
	$modelsLocation = "application/models";

	mkdir($controllerLocation, 0777, true);
	mkdir($viewsLocation, 0777, true);

	if ($controllerLocation) {

		$controller = fopen($controllerLocation . "/" . ucfirst($name) . ucfirst($name2). ".php", "w+");
		$controllerContent = "<?php
		if (!defined('BASEPATH'))
			exit('No direct script access allowed');
		class " . ucfirst($name) .ucfirst($name2) . " extends MY_Controller {
			
			function __construct()
			{
				parent::__construct();
				\$this->load->library('form_validation');
				// \$this->load->model('m_".$nama.ucfirst($name2)."');
				\$this->load->helper('url');
				\$this->load->helper('common_helper');
				// if (!\$this->session->userdata('is_login')) {
				// 	redirect('login');
				// }
				\$this->module = \$this->router->fetch_module();
				\$this->isi = ['header_custom' => \$this->module . '/v-header-custom', 'footer_custom' => \$this->module . '/v-footer-custom'];
			}
			function index()
			{
				\$data['page'] = 'monitoring';
				// \$this->isi['".$nama.ucfirst($name2)."'] = \$this->m_".$nama.ucfirst($name2)."->get_".ucfirst($nama).ucfirst($name2)."();
				\$this->isi['view_content']	= \$this->load->view('v-" . $name . "-".$name2."', '', TRUE);
				// var_dump(\$this->isi['view_content']);
				\$this->load->view('pages/v-main', \$this->isi);
			}
		}
		?>";

		if ($controller) {
			fwrite($controller, $controllerContent);
			fclose($controller);
		} else {
			echo "failed";
		}

		echo "Controller created..\n";
	} else {
		echo "Fail...\n";
	}

	if ($modelsLocation) {
		$models = fopen($modelsLocation . "/Mdl" . ucfirst($name)  . ucfirst($name2). ".php", "w+");

		$modelsContent = "<?php
		defined('BASEPATH') or exit('No direct script access allowed');
		class Mdl" . ucfirst($name) .ucfirst($name2). " extends CI_Model {
			public function __construct() {
				parent::__construct();
			}
			public function get" . ucfirst($name).ucfirst($name2) . "() {
				echo 'get" . ucfirst($name).ucfirst($name2) . "';
			}
			
			public function update" . ucfirst($name).ucfirst($name2) . "(\$data) {
				echo 'update" . ucfirst($name).ucfirst($name2) . "';
			}
			public function add" . ucfirst($name).ucfirst($name2) . "(\$data) {
				echo 'add" . ucfirst($name).ucfirst($name2) . "';
			}
			public function delete" . ucfirst($name).ucfirst($name2) . "(\$data) {
				echo 'delete" . ucfirst($name).ucfirst($name2) . "';
			}
		}";

		if ($models) {
			fwrite($models, $modelsContent);
			fclose($models);
		} else {
			echo "failed";
		}

		echo "Controller created..\n";
	}
	if ($viewsLocation) {

		$vcontent = fopen($viewsLocation . "/v-" . $name ."-".$name2. ".php", "w+");
		$vheader = fopen($viewsLocation . "/v-footer-custom.php", "w+");
		$vfooter = fopen($viewsLocation . "/v-header-custom.php", "w+");

		$viewContent = "<h2>" . $name . $name2 .  "</h2> ";
		$customContent = "<!-- VIEWS --> ";

		if ($vcontent) {
			fwrite($vcontent, $viewContent);
			fwrite($vheader, $customContent);
			fwrite($vfooter, $customContent);
			fclose($vcontent);
			fclose($vheader);
			fclose($vfooter);
		} else {
			echo "failed";
		}
		echo "View created..\n";

		echo "Finish ...\n";
	} else {
		echo "Fail...\n";
	}

}
