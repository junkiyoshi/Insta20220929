#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 30;
	int radius_max = span * 0.48;
	int radius_min = span * 0.05;

	for (int x = span * 0.5; x <= ofGetWidth() - span * 0.5; x += span) {

		for (int y = span * 0.5; y <= ofGetHeight() - span * 0.5; y += span) {

			auto sin_value = sin(x * 0.005 + ofGetFrameNum() * 0.05);
			auto sin_y = ofMap(sin_value, -1, 1, 120, ofGetHeight() - 120);

			auto location = glm::vec2(x, y);
			auto sin_location = glm::vec2(x, sin_y);
			auto distance = glm::distance(location, sin_location);

			ofSetColor(239, 39, 39);
			if (distance < 100) {

				ofDrawCircle(location, ofMap(distance, 0, 100, radius_max, radius_min));
			}
			else {

				ofDrawCircle(location, radius_min);
			}

			auto cos_value = cos(x * 0.005 + ofGetFrameNum() * 0.05);
			auto cos_y = ofMap(cos_value, -1, 1, 120, ofGetHeight() - 120);

			location = glm::vec2(x, y);
			auto cos_location = glm::vec2(x, cos_y);
			distance = glm::distance(location, cos_location);

			ofSetColor(39, 39, 239);
			if (distance < 100) {

				ofDrawCircle(location, ofMap(distance, 0, 100, radius_max, radius_min));
			}
			else {

				ofDrawCircle(location, radius_min);
			}

			auto noise_value = ofNoise(x * 0.005 + ofGetFrameNum() * 0.03);
			auto noise_y = ofMap(noise_value, 0, 1, 120, ofGetHeight() - 120);

			location = glm::vec2(x, y);
			auto noise_location = glm::vec2(x, noise_y);
			distance = glm::distance(location, noise_location);

			ofSetColor(39, 239, 39);
			if (distance < 100) {

				ofDrawCircle(location, ofMap(distance, 0, 100, radius_max, radius_min));
			}
			else {

				ofDrawCircle(location, radius_min);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}