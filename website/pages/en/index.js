/**
 * Copyright (c) 2017-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

const React = require('react');

const CompLibrary = require('../../core/CompLibrary.js');
const MarkdownBlock = CompLibrary.MarkdownBlock; /* Used to read markdown */
const Container = CompLibrary.Container;
const GridBlock = CompLibrary.GridBlock;

const siteConfig = require(process.cwd() + '/siteConfig.js');

class Button extends React.Component {
  render() {
    return (
      <div className="pluginWrapper buttonWrapper" id={this.props.key}>
        <a className="button" href={this.props.href} target={this.props.target}>
          {this.props.children}
        </a>
      </div>
    );
  }
}

Button.defaultProps = {
  target: '_self',
};

class HomeSplash extends React.Component {
  render() {
    return (
      <div className="homeContainer">
        <div className="homeSplashFade">
          <div className="wrapper homeWrapper">
            <div className="projectLogo">
              <img src={siteConfig.baseUrl + 'img/QInstallerBridge.png'} />
            </div>
            <div className="inner">
              <h2 className="projectTitle">
                {siteConfig.title}
                <small>{siteConfig.tagline}</small>
              </h2>
              <div className="section promoSection">
                <div className="promoRow">
                  <div className="pluginRowBlock">
                    <Button
                      href={
                        siteConfig.baseUrl +
                        'docs/' +
                        'Installation.html'
                      }>
                      Get Started
                    </Button>
                    <Button
                      href={
                        siteConfig.baseUrl +
                        'docs/' +
                        'QInstallerBridgeErrorCodes.html'
                      }>
                      API Reference
                    </Button>
	            <Button href={'https://github.com/antony-jr/QInstallerBridge'}>
	    	      View on Github
	    	    </Button>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    );
  }
}

class Index extends React.Component {
  render() {
    let language = this.props.language || 'en';
    const showcase = siteConfig.users
      .filter(user => {
        return user.pinned;
      })
      .map(user => {
        return (
          <a href={user.infoLink}>
            <img src={user.image} title={user.caption} />
          </a>
        );
      });

    return (
      <div>
        <HomeSplash language={language} />
        <div className="mainContainer">
          <Container padding={['bottom', 'top']}>
            <GridBlock
              align="center"
              contents={[
                {
                  content: 'QInstallerBridge fully supports Qt Projects by flowing with its event loop and'+
			   ' thus you will have no problem integrating QInstallerBridge with your Qt Project.',
                  image: siteConfig.baseUrl + 'img/qt.png',
                  imageAlign: 'top',
                  title: 'Supports Qt\'s Event Loop.',
                },
		{
                  content: 'Whether you are Updating or checking for Updates QInstallerBridge does not '+
                           'need Qt Installer Framework , (i.e) The <b>Maintainance Tool</b> for anything ' +
                           'and thus makes QInstallerBridge work on its own and also flowing with the Maintainance Tool.',
                  image: siteConfig.baseUrl + 'img/depend.png',
                  imageAlign: 'top',
                  title: 'Does not depend on Qt Installer Framework',
                },
		{
                  content: 'QInstallerBridge only operates with the configuration files generated by Qt Installer Framework '+
                           'and this is only used to communicate with the <b>Maintainance Tool</b> to let it know about ' +
                           'the newly installed update , to avoid re-update!',
                  image: siteConfig.baseUrl + 'img/config.png',
                  imageAlign: 'top',
                  title: 'Only Requires Configuration!',
                },
		{
                  content: 'QInstallerBridge does not like leaving heavy traces for the users and thus '+
                           'it is packed with all its amazing features in a single C++ header file , this ' +
                           'makes QInstallerBridge easier to integrate with your project.',
                  image: siteConfig.baseUrl + 'img/header.png',
                  imageAlign: 'top',
                  title: 'Header only library!',
                },
		{
                  content: '<center>This project is rated by <b>Codacy</b> with a <b>A Project Certification</b><br>' +
                           ' and thus integrating this header will not affect your source , So this project is also<br>'+
                           ' best suited for those who care about code taste.<br></center>',
                  image: siteConfig.baseUrl + 'img/clean_code.png',
                  imageAlign: 'top',
                  title: '<center>Clean C++ API.</center>',
                },

              ]}
              layout="fourColumn"
            />
          </Container>

          <Container padding={['bottom', 'top']} background="dark">
            <GridBlock
              contents={[
                {
                  content:
			'Ever wanted to make your applications work with the flow but stuck with Qt\'s Maintanance Tool.'+
			'I belive that updates should be just installed without any complications but that does not mean '+
			'Qt Installer Framework is a bluff , its actually the coolest thing a vendor can have. With Qt\'s '+
			'Installer Framework you can ship your packages to Linux , Windows and Mac with a cross-platform gui '+
			'installer but the one thing that sucks is that Qt does not provide a auto update officially but it '+
			'does have theMaintanance Tool which can auto update. Some cool folks used QProcess to communicate with '+
			'the Maintanance Tool and that did work as a hotfix but I needed a solid and clean API to communicate '+
			'with Qt\'s Maintanance Tool and thus QInstallerBridge was born.',                  
		 image: siteConfig.baseUrl + 'img/QInstallerBridge.png',
                 imageAlign: 'right',
		 title: 'Why Create QInstallerBridge ?',
                },
              ]}
            />
          </Container>

          <div className="productShowcaseSection paddingBottom">
            <h2>{"Who's Using This?"}</h2>
            <p>This project is used by all these people</p>
            <div className="logos">{showcase}</div>
            <div className="more-users">
              <a
                className="button"
                href={
                  siteConfig.baseUrl + this.props.language + '/' + 'users.html'
                }>
                More {siteConfig.title} Users
              </a>
            </div>
          </div>
        </div>
      </div>
    );
  }
}

module.exports = Index;