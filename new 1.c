Creating your Facebook Application 

public function redirectToAuthorization()
{
    $config = array(
      'appId' => '1386038978283XXX',
      'secret' => '9ec32a48f1ad1988e0d4b9e80a17dXXX',
      'allowSignedRequest' => false
    );

    $facebook = new \Facebook($config);

    die('Todo: Redirect to Facebook');
}
Redirecting the User
public function redirectToAuthorization()
{
    // ...

    $redirectUrl = $this->generateUrl(
        'facebook_authorize_redirect',
        array(),
        true
    );

    $url = $facebook->getLoginUrl(array(
        'redirect_uri' => $redirectUrl,
        'scope' => array('publish_actions', 'email')
    ));

    die('Todo: Redirect to Facebook');
}

Getting the Access Token 
public function redirectToAuthorization()
{
    $facebook = $this->createFacebook();
    // ... the rest of the original function
}

public function receiveAuthorizationCode(Application $app, Request $request)
{
    $facebook = $this->createFacebook();

    die('Todo: Handle after Facebook redirects to us');
}

private function createFacebook()
{
    $config = array(
      'appId' => '1386038978283XXX',
      'secret' => '9ec32a48f1ad1988e0d4b9e80a17dXXX',
      'allowSignedRequest' => false
    );

    return new \Facebook($config);
}

public function receiveAuthorizationCode(Application $app, Request $request)
{
    $facebook = $this->createFacebook();

    $userId = $facebook->getUser();
    var_dump($userId);die;

    die('Todo: Handle after Facebook redirects to us');
}

Saving the Facebook User ID
public function receiveAuthorizationCode(Application $app, Request $request)
{
    $facebook = $this->createFacebook();
    $userId = $facebook->getUser();
    // ...

    $user = $this->getLoggedInUser();
    $user->facebookUserId = $userId;
    $this->saveUser($user);

    return $this->redirect($this->generateUrl('home'));
}